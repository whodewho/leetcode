/*
O(N)
 */
class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> res;
            if(rowIndex<0)return res;
            res.push_back(1);
            for(int i=1;i<=rowIndex;i++)
            {
                vector<int> tmp;
                tmp.push_back(1);
                for(int j=1;j<i;j++)
                    tmp.push_back(res[j-1]+res[j]);
                tmp.push_back(1);
                res=tmp;
            }
            return res;
        }
};
