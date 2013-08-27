/*
   dp.
   one bullet
   i am curious about leetcode's compile. like cin>>n>>m; int a[n][m]; this works!
   anson's word[i]!=word[j], good!
 */
class Solution {
    public:
        int minDistance(string word1, string word2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n=word1.size();
            int m=word2.size();
            vector<vector<int> > C;
            for(int i=0;i<=n;i++)
            {
                vector<int> tmp;
                for(int j=0;j<=m;j++)
                {
                    tmp.push_back(0);
                }
                C.push_back(tmp);
            }
            for(int i=0;i<=n;i++)
            {
                C[i][0]=i;
            }
            for(int j=0;j<=m;j++)
            {
                C[0][j]=j;
            }

            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=m;j++)
                {
                    int t=1;
                    if(word1[i-1]==word2[j-1])
                    {
                        t=0;
                    }

                    C[i][j]=min(min(C[i-1][j]+1,C[i][j-1]+1),C[i-1][j-1]+t);
                }
            }

            return C[n][m];
        }

        int minDistance(string word1, string word2) {
            int M = word1.size();
            int N = word2.size();
            int dp[M+1][N+1];
            dp[0][0] = 0;
            for (int i = 1; i <= M; i++)
                dp[i][0] = i;
            for (int j = 1; j <= N; j++)
                dp[0][j] = j;

            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    dp[i][j] = min(min(dp[i-1][j] + 1, dp[i][j-1] + 1), dp[i-1][j-1] + (word1[i-1] != word2[j-1]));
                }
            }

            return dp[M][N];
        }
};
