/*
   the second and third solution are anson's.
   mine is better. although, i goolge the formular.  a little transformation is awsome.
   as you can see, the three are the same
   h(n)= h(0)*h(n-1)+h(1)*h(n-2) + ... + h(n-1)h(0) (其中n>=2)
   h(n)=((4*n-2)/(n+1))*h(n-1);
   h(n)=C(2n,n)/(n+1) (n=1,2,3,...)
 */
class Solution {
    public:
        int numTrees(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> vec;
            vec.push_back(1);

            for(int i=1;i<n+1;i++)
            {
                vec.push_back(vec[i-1]*(4*i-2)/(i+1));
            }
            return vec[n];
        }

        int numTrees1(int n) {
            if (n < 2) return 1;
            int res = 0;
            for (int i = 0; i < n; i++)
                res += numTrees1(i)*numTrees1(n-i-1);
            return res;
        }

        int numTrees2(int n) {
            int dp[n+1];
            memset(dp, 0, (n+1)*sizeof(int));
            dp[0] = 1;
            dp[1] = 1;
            for (int i = 2; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    dp[i] += dp[j]*dp[i-j-1];
                }
            }
            return dp[n];
        }
};
