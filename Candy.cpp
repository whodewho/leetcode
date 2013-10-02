/*
   first is a circle solution. I thought too much. they are in a line. it's easier

   second try is the solution, when it turns to be a line, boring
   about 2 2 1 the result is 1 2 1, be careful, only greater than neightbor, you need give more, when equal, it's ok

   the third, got a better one
 */
class Solution {
    public:
        int candy(vector<int> &ratings) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int n = ratings.size();
            if (n == 1)
                return 1;

            vector<int> leftMin(n, -1);
            vector<int> rightMin(n, -1);

            int j = 0;
            if (ratings[j] < ratings[n - 1])
                j = 0;
            else {
                j = n - 1;
                while (j > 0 && ratings[(j - 1 + n) % n] <= ratings[j])
                    j = (j - 1 + n) % n;
            }
            leftMin[0] = ratings[0]==ratings[j]?0:j;
            for (int i = 1; i < n; i++) {
                if (ratings[i] > ratings[i - 1]
                        || (ratings[i] == ratings[i - 1] && leftMin[i - 1] != i - 1)) {
                    leftMin[i] = leftMin[i - 1];
                } else {
                    leftMin[i] = i;
                }
            }

            j = n - 1;
            if (ratings[j] < ratings[0])
                j = n - 1;
            else {
                j = 0;
                while (j < n - 1 && ratings[j] >= ratings[(j + 1) % n])
                    j = (j + 1) % n;
            }
            rightMin[n - 1] = ratings[n-1]==ratings[j]?n-1:j;
            for (int i = n - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]
                        || (ratings[i] == ratings[i + 1] && rightMin[i + 1] != i + 1)) {
                    rightMin[i] = rightMin[i + 1];
                } else {
                    rightMin[i] = i;
                }
            }

            vector<int> results(n,0);
            for (int i = 0; i < n; i++) {
                if (leftMin[i] == rightMin[i] && leftMin[i] == i)
                    results[i] = 1; //botom
                else {
                    if (ratings[(i - 1 + n) % n] <= ratings[i]
                            && ratings[i] <= ratings[(i + 1) % n]) {
                        //go up
                        results[i] = (i + n - leftMin[i]) % n + 1;
                    } else if (ratings[(i - 1 + n) % n] >= ratings[i]
                            && ratings[i] >= ratings[(i + 1) % n]) {
                        //go down
                        results[i] = (rightMin[i] + n - i) % n + 1;
                    } else {
                        //peak
                        results[i] = max((i + n - leftMin[i]) % n + 1,
                                (rightMin[i] + n - i) % n + 1);
                    }
                }
            }

            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += results[i];
            return sum;
        }


        int candy(vector<int> &ratings) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int n = ratings.size();
            if (n == 1)
                return 1;

            vector<int> leftMin(n, -1);
            vector<int> rightMin(n, -1);

            leftMin[0] = 0;
            for (int i = 1; i < n; i++) {
                if (ratings[i] > ratings[i - 1]) {
                    leftMin[i] = leftMin[i - 1];
                } else {
                    leftMin[i] = i;
                }
            }

            rightMin[n - 1] = n - 1;
            for (int i = n - 2; i >= 0; i--) {
                if (ratings[i] > ratings[i + 1]) {
                    rightMin[i] = rightMin[i + 1];
                } else {
                    rightMin[i] = i;
                }
            }

            vector<int> results(n, 0);
            if (ratings[0] <= ratings[1])
                results[0] = 1;
            else
                results[0] = rightMin[0] + 1;

            if (ratings[n - 1] <= ratings[n - 2])
                results[n - 1] = 1;
            else
                results[n - 1] = n - leftMin[n - 1];

            for (int i = 1; i < n - 1; i++) {
                if (leftMin[i] == rightMin[i] && leftMin[i] == i)
                    results[i] = 1; //botom
                else {
                    if (ratings[i - 1] < ratings[i] && ratings[i] < ratings[i + 1]) {
                        //go up
                        results[i] = i - leftMin[i] + 1;
                    } else if (ratings[i - 1] > ratings[i]
                            && ratings[i] > ratings[i + 1]) {
                        //go down
                        results[i] = rightMin[i] - i + 1;
                    } else {
                        //peak
                        results[i] = max(i - leftMin[i] + 1, rightMin[i] - i + 1);
                    }
                }
            }

            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += results[i];
            return sum;
        }

        int candy(vector<int> &ratings) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int n = ratings.size();
            if (n == 1)
                return 1;

            vector<int> results(n, 0);

            for(int i=0;i<n;i++)
            {
                if(i==0)
                {
                    if(ratings[0]<=ratings[1])
                        results[0]=1;
                    continue;
                }
                if(i==n-1)
                {
                    if(ratings[n-2]>=ratings[n-1])
                        results[n-1]=1;
                    else
                        results[n-1]=results[n-2]+1;
                    continue;
                }

                if(ratings[i]<=ratings[i+1]&&ratings[i]<=ratings[i-1])
                    results[i]=1;
                else if(ratings[i-1]<ratings[i])
                    results[i]=results[i-1]+1;
            }

            for(int i=n-2;i>=0;i--)
            {
                if(ratings[i]>ratings[i+1])
                    results[i]=max(results[i],results[i+1]+1);
            }

            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += results[i];
            return sum;
        }
};
