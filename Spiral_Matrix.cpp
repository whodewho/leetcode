/*
O(M*N)
 */
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int> > &matrix) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> result;
            int m=matrix.size();
            if(!m)return result;
            int n=matrix[0].size();
            if(!n)return result;

            vector<vector<int>> res(m,vector<int>(n,0));

            int direction=1,i=0,j=0;
            for(int k=1;k<=m*n;k++)
            {
                result.push_back(matrix[i][j]);
                res[i][j]=1;
                if(direction==1)
                {
                    if(j<n-1&&res[i][j+1]==0)
                        j++;
                    else
                    {
                        i++;
                        direction=2;
                    }
                }
                else if(direction==2)
                {
                    if(i<m-1&&res[i+1][j]==0)
                        i++;
                    else
                    {
                        j--;
                        direction=3;
                    }
                }
                else if(direction==3)
                {
                    if(j>0&&res[i][j-1]==0)
                        j--;
                    else
                    {
                        i--;
                        direction=4;
                    }
                }
                else if(direction==4)
                {
                    if(i>0&&res[i-1][j]==0)
                        i--;
                    else
                    {
                        j++;
                        direction=1;
                    }
                }
            }
            return result;
        }
};
