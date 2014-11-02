/*
O(pow(2,N))
*/
class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int>> res;
            if(numRows==0)return res;
            res.push_back(vector<int>(1,1));
            for(int i=1;i<numRows;i++)
            {
                vector<int> item;
                //item.reserve(i+1);
                item.push_back(1);
                for(int j=1;j<i;j++)
                {
                    item.push_back(res[i-1][j]+res[i-1][j-1]);
                }
                item.push_back(1);
                res.push_back(item);
            }
            return res;
        }
};
