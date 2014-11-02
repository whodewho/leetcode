/*
    dfs
    O(pow(k, n))
   */
class Solution {
    public:
        void worker(int index,string &path,string &digits,string dict[10],vector<string> &result)
        {
            if(index==digits.size())
            {
                result.push_back(path);
                return;
            }

            for(string::size_type i=0;i<dict[digits[index]-'0'].size();i++)
            {
                path.append(1,dict[digits[index]-'0'][i]);
                worker(index+1,path,digits,dict,result);
                path.pop_back();
            }
        }

        vector<string> letterCombinations(string digits) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> result;
            string dict[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
            string path="";
            worker(0,path,digits,dict,result);
            return result;
        }
};
