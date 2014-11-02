/*
    rabbbit,rabbit, return 3, how?
    which 3?
    got it:rabbit,rabbit,rabbit...
   */
/*
O(M*N)
O(M*N)
*/
class Solution {
    public:
        int numDistinct(string S, string T) {
            int M = S.size();
            int N = T.size();
            int dp[M+1][N+1];
            dp[0][0] = 1;
            for (int i = 1; i <= M; i++) dp[i][0] = 1;
            for (int j = 1; j <= N; j++) dp[0][j] = 0;
                
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    if (T[j-1] == S[i-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    else dp[i][j] = dp[i-1][j];
                }
            }
            return dp[M][N];
        }
};
