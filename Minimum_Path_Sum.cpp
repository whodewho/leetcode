/*
    the second is anson's, we do this in reverse way
    he prefer one loop, as you can see
    he declare arrays too casually
   */
class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m=grid.size();
            if(!m)return 0;
            int n=grid[0].size();
            if(!n)return 0;

            int **p=(int **)malloc(sizeof(int)*m);
            for(int k=0;k<m;k++)
                p[k]=(int *)malloc(sizeof(int)*n);

            p[m-1][n-1]=grid[m-1][n-1];
            for(int k=m-2;k>=0;k--)
                p[k][n-1]=p[k+1][n-1]+grid[k][n-1];
            for(int k=n-2;k>=0;k--)
                p[m-1][k]=p[m-1][k+1]+grid[m-1][k];

            for(int i=m-2;i>=0;i--)
                for(int j=n-2;j>=0;j--)
                    p[i][j]=grid[i][j]+min(p[i+1][j],p[i][j+1]);
            return p[0][0];
        }
        
        int minPathSum(vector<vector<int> > &grid) {
            int M = grid.size();
            if (M == 0) return 0;
            int N = grid[0].size();
            if (N == 0) return 0;

            int dp[M][N];
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (i == 0 && j == 0) dp[i][j] = grid[i][j];
                    else if (i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];
                    else if (j == 0) dp[i][j] = dp[i-1][j] + grid[i][j];
                    else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
                }
            }
            return dp[M-1][N-1];
        }
};
