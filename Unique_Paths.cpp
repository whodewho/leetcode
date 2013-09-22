/*
   anson is changing
   look at my second try
 */
class Solution {
    public:
        int uniquePaths(int m, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(m==0)return 0;
            if(n==0)return 0;

            int **p=(int **)malloc(sizeof(int)*m);
            for(int k=0;k<m;k++)
                p[k]=(int *)malloc(sizeof(int)*n);

            for(int i=m-1;i>=0;i--)
                for(int j=n-1;j>=0;j--)
                {
                    if(i==m-1||j==n-1)p[i][j]=1;               
                    else p[i][j]=p[i+1][j]+p[i][j+1];
                }
            return p[0][0];
        }

        int uniquePaths(int m, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(m==0||n==0)return 0;
            vector<vector<int> > f(m,vector<int>(n,1));
            for(int i=m-2;i>=0;i--)
                for(int j=n-2;j>=0;j--)
                    f[i][j]=f[i+1][j]+f[i][j+1];
            return f[0][0];
        }
};
