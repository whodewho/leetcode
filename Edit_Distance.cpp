/*
O(M*N)
O(M*N)
*/
class Solution {
    public:
    
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
