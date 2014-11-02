/*
    O(N^2)
*/
    
class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> table = triangle.back();
            int N=triangle.size();
            for(int i=N-2;i>=0;i--)
            {
                for(int j=0;j<=i;j++)
                {
                    table[j]=triangle[i][j]+min(table[j], table[j+1]);
                }
            }
            return table[0];
        }
};
