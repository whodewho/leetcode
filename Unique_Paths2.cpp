/*
O(M*N)
 */
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int m=obstacleGrid.size();
            if(!m)return 0;
            int n=obstacleGrid[0].size();
            if(!n)return 0;

            vector<vector<int> > f(m,vector<int>(n,0));
            for(int i=m-1;i>=0;i--)
                for(int j=n-1;j>=0;j--)
                {
                    if(i==m-1&&j==n-1)f[i][j]=obstacleGrid[i][j]==1?0:1;
                    else if(i==m-1)f[i][j]=obstacleGrid[i][j]==1?0:f[i][j+1];
                    else if(j==n-1)f[i][j]=obstacleGrid[i][j]==1?0:f[i+1][j];
                    else f[i][j]=obstacleGrid[i][j]==1?0:(f[i+1][j]+f[i][j+1]);
                }

            return f[0][0];
        }
};
