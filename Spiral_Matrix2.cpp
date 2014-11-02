/*
O(N*N)
 */

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int>> res(n,vector<int>(n,0));
            int direction=1,i=0,j=0;
            for(int k=1;k<=n*n;k++)
            {
                res[i][j]=k;
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
                    if(i<n-1&&res[i+1][j]==0)
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
            return res;
        }

        vector<vector<int> > generateMatrix(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > result(n,vector<int>(n,0));
            int runner=1;
            for(int i=0,l=n;i<=n/2&&l>=1;i++,l-=2)
            {
                int j=i,k=i;
                if(l==1)
                {
                    result[j][k]=runner;
                    break;
                }

                for(int t=0;t<l-1;t++)
                {
                    result[j][k+t]=runner++;
                }
                for(int t=0;t<l-1;t++)
                {
                    result[j+t][k+l-1]=runner++;
                }
                for(int t=0;t<l-1;t++)
                {
                    result[j+l-1][k+l-1-t]=runner++;
                }
                for(int t=0;t<l-1;t++)
                {
                    result[j+l-1-t][k]=runner++;
                }
            }
            return result;
        }
};
