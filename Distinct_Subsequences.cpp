/*
    rabbbit,rabbit, return 3, how?
    which 3?
    got it:rabbit,rabbit,rabbit...
    
    f[i][j]=f[i-1][j-1]+f[i][j-1] when t[i]==s[j]
    else f[i][j]=f[i][j-1]
   */
class Solution {
    public:
        int numDistinct(string S, string T) {
            int N = S.size();
            int M = T.size();
            int dp[M+1][N+1];
            dp[0][0] = 1;
            for (int i = 1; i <= M; i++) dp[i][0] = 0;
            for (int j = 1; j <= N; j++) dp[0][j] = 1;
            for (int i = 1; i <= M; i++) {
                for (int j = 1; j <= N; j++) {
                    if (T[i-1] == S[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                    else dp[i][j] = dp[i][j-1];
                }
            }
            return dp[M][N];
        }
};
