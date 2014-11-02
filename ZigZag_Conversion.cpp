//O(N)

class Solution {
    public:
        string convert(string s, int nRows) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(nRows==1)return s;
            vector<string> result(nRows, "");
            for (string::size_type i = 0; i < s.size(); i++) {
                int tmp = i % (2 * nRows - 2);
                if (tmp <= nRows - 1) {
                    result[tmp].append(1, s[i]);
                } else {
                    result[2 * nRows - 2 - tmp].append(1, s[i]);
                }
            }
            string res = "";
            for (int i = 0; i < nRows; i++) {
                res.append(result[i]);
            }
            return res;
        }
};
