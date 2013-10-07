/*
   from anson, good job.
   the dirty "fill(begin,end,val)", be careful.
   dp does not work here, you can not get a[i][j] from a[i-1][j],a[i][j-1],a[i-1][j-1]

   look at the second try, almost same
 */
class Solution {
    public:
        int maximalRectangle(vector<vector<char> > &matrix) {
            return maximalRectangle2(matrix);
        }

        // based on dynamic programming, takes O(n^3) time
        int maximalRectangle1(vector<vector<char> > &matrix) {
            int M = matrix.size();
            if (M == 0) return 0;
            int N = matrix[0].size();
            if (N == 0) return 0;
            int dp[M][N];
            fill(&dp[0][0], &dp[M][0], 0);

            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (matrix[i][j] == '1') {
                        dp[i][j] = (j > 0) ? (dp[i][j-1] + 1) : 1;
                    }
                }
            }

            int res = 0;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    int min = dp[i][j];
                    int k = i;
                    while (k >= 0) {
                        if (dp[k][j] < min) min = dp[k][j];
                        res = max(res, min * (i - k + 1));
                        k--;
                    }
                }
            }
            return res;
        }

        // based on stack, takes O(n^2) time
        int maximalRectangle2(vector<vector<char> > &matrix) {
            int M = matrix.size();
            if (M == 0) return 0;
            int N = matrix[0].size();
            if (N == 0) return 0;
            int h[N];
            fill(h, h + N, 0);
            int res = 0;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (matrix[i][j] == '1') h[j]++;
                    else h[j] = 0;
                }
                res = max(res, largestRectangleinHistogram2(h, N));
            }
            return res;
        }

        int largestRectangleinHistogram2(int x[], int n) {
            int y[n];
            stack<int> stk;
            for (int i = 0; i < n; i++) {
                while (!stk.empty()) {
                    if (x[i] <= x[stk.top()]) stk.pop();
                    else break;
                }
                int j = (stk.empty()) ? -1 : stk.top();
                // Calculating number of bars on the left
                y[i] = i - j - 1;
                stk.push(i);
            }

            while (!stk.empty()) stk.pop();

            for (int i = n - 1; i > 0; i--) {
                while (!stk.empty()) {
                    if (x[i] <= x[stk.top()]) stk.pop();
                    else break;
                }
                int j = (stk.empty()) ? n : stk.top();
                // Calculating number of bars on the left + right
                y[i] += (j - i - 1);
                stk.push(i);
            }

            int res = 0;
            for (int i = 0; i < n; i++) {
                // Calculating height * width
                y[i] = x[i] * (y[i] + 1);
                if (y[i] > res) res = y[i];
            }
            return res;
        };



        //second try
        int maximalRectangle(vector<vector<char> > &matrix) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int m=matrix.size();
            if(!m)return 0;
            int n=matrix[0].size();
            if(!n)return 0;

            int result=0;
            vector<int> h(n,0);
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]=='0')
                        h[j]=0;
                    else
                        h[j]++;
                }

                vector<int> leftBars(n,0);
                stack<int> leftStack;
                for(int j=0;j<n;j++)
                {
                    while(!leftStack.empty()&&h[leftStack.top()]>=h[j])
                        leftStack.pop();
                    if(leftStack.empty())
                        leftBars[j]=h[j]*j;
                    else
                        leftBars[j]=h[j]*(j-leftStack.top()-1);
                    leftStack.push(j);
                }

                vector<int> rightBars(n,0);
                stack<int> rightStack;
                for(int j=n-1;j>=0;j--)
                {
                    while(!rightStack.empty()&&h[rightStack.top()]>=h[j])
                        rightStack.pop();
                    if(rightStack.empty())
                        rightBars[j]=h[j]*(n-j-1);
                    else
                        rightBars[j]=h[j]*(rightStack.top()-j-1);
                    rightStack.push(j);
                }

                for(int j=0;j<n;j++)
                {
                    result=max(result,leftBars[j]+h[j]+rightBars[j]);
                }
            }

            return result;
        }
};
