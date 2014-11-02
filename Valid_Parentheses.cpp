/*
    0 milli secs on large data, I am on fire!
   */
//O(N)
//O(N)
class Solution {
    public:
        bool isValid(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            stack<char> stk;
            for(string::size_type i=0;i<s.size();i++)
            {
                if(stk.empty())
                {
                    stk.push(s[i]);
                    continue;
                }
                if(s[i]==')'&&stk.top()=='('||s[i]=='}'&&stk.top()=='{'||s[i]==']'&&stk.top()=='[')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(s[i]);
                }
            }
            return stk.empty();
        }
};
