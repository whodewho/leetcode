/*the second is anson's
 */
class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i=0;
            string result="";
            if(strs.empty())return result;
            while(true)
            {
                int j=0;
                for(;j<strs.size();j++)
                {
                    if(strs[j].empty())return "";
                    if(i>strs[j].size()-1||strs[j][i]!=strs[0][i])
                    {
                        break;
                    }
                }
                if(j<strs.size())
                {
                    result=strs[0].substr(0,i);
                    break;
                }
                else 
                {
                    i++;
                }
            }
            return result;
        }

        string longestCommonPrefix(vector<string> &strs) {
            int N = strs.size();
            if (N == 0) return "";
            int l = 0;
            while (l < strs[0].size()) {
                for (int i = 1; i < N; i++) {
                    if (l == strs[i].size() || strs[i][l] != strs[0][l])
                        return strs[i].substr(0, l);
                }
                l++;
            }
            return strs[0];
        }
};
