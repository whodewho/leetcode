/*
   mark and sweep!
   long time no see, leetcode. long time no see, anson. let me check yours.
   anson, yours is better. I thougt of that, however, at last, turned to this one
   the second one is anson's, n*n than mine n*n*n. be careful of the first line and row
 */
class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m=matrix.size();
            if(m==0)return;
            int n=matrix[0].size();
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]==0)
                    {
                        for(int k=0;k<n;k++)
                        {
                            if(k==j)continue;
                            if(matrix[i][k]==0)continue;
                            matrix[i][k]=-1;
                        }
                        for(int k=0;k<m;k++)
                        {
                            if(k==i)continue;
                            if(matrix[k][j]==0)continue;
                            matrix[k][j]=-1;
                        }
                    }
                }
            }

            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]==-1)
                        matrix[i][j]=0;
                }

        }

        void setZeroes(vector<vector<int> > &matrix) {
            int row = matrix.size();
            int col = matrix[0].size();
            bool firstRow = false;
            bool firstCol = false;
            for(int i = 0; i < row; i++) {
                if(matrix[i][0] == 0) {
                    firstCol = true;
                    break;
                }
            }
            for(int i = 0; i < col; i++) {
                if(matrix[0][i] == 0) {
                    firstRow = true;
                    break;
                }
            }
            for(int i = 1; i < row; i++) {
                for(int j = 1; j < col; j++) {
                    if(matrix[i][j] == 0) {
                        matrix[0][j] = matrix[i][0] = 0;
                    }
                }
            }
            for(int i = 1; i < row; i++) {
                for(int j = 1; j < col; j++) {
                    if(matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
                }
            }
            if(firstRow) {
                for(int j = 0; j < col; j++) {
                    matrix[0][j] = 0;
                }
            }
            if(firstCol) {
                for(int i = 0; i < row; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
};
