/*
O(M*N)
 */
class Solution {
    public:

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
