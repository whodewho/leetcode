/*
   this is a O(2k) sulution. ok, i take it as O(k).
   anson offerred a tricker sulution. 
   which one is better? you name it.
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
        vector<int> getRow1(int rowIndex)
        {
            vector<int> res;
            res.reserve(rowIndex+1);
            res.push_back(1);
            if (rowIndex < 1) return res;
            res.push_back(1);
            int m = 1;
            while (m < rowIndex)
            {
                for (int i = 0; i < m; i++)
                    res[i] += res[i+1];
                res.insert(res.begin(), 1);
                m++;
            }
            return res;
        }

};
