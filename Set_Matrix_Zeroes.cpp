/*
  O(N*N)
 */
class Solution {
    public:

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

        void setZeroes(vector<vector<int> > &matrix) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m=matrix.size();
            if(!m)return;
            int n=matrix[0].size();
            if(!n)return;
            vector<int> head(n,1);
            for(int i=0;i<m;i++)
            {
                bool sign=false;
                for(int j=0;j<n;j++)
                {
                    if(matrix[i][j]==0)
                    {
                        sign=true;
                        head[j]=0;
                    }
                }
                if(sign)
                {
                    for(int j=0;j<n;j++)
                        matrix[i][j]=0;
                }
            }
            for(int j=0;j<n;j++)
            {
                if(head[j]==0)
                {
                    for(int i=0;i<m;i++)
                        matrix[i][j]=0;
                }
            }
            return;
        }
};
