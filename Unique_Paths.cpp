/*
    anson is changing
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
};
