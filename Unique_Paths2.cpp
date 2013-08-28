/*
    easy
   */
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m=obstacleGrid.size();
            if(m==0)return 0;
            int n=obstacleGrid[0].size();
            if(n==0)return 0;

            int **p=(int **)malloc(sizeof(int)*m);
            for(int k=0;k<m;k++)
                p[k]=(int *)malloc(sizeof(int)*n);

            for(int i=m-1;i>=0;i--)
                for(int j=n-1;j>=0;j--)
                {
                    if(obstacleGrid[i][j])
                    {
                        p[i][j]=0;
                        continue;
                    }
                    if(i==m-1&&j==n-1)p[i][j]=!obstacleGrid[i][j];
                    else if(i==m-1)p[i][j]=p[i][j+1];
                    else if(j==n-1)p[i][j]=p[i+1][j];
                    else p[i][j]=p[i+1][j]+p[i][j+1];
                }
            return p[0][0];
        }
};
