/*
    the second is anson's, his is better
   */
class Solution {
    public:
        int longestValidParentheses(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> badPoint;
            stack<int> indexStk;
            badPoint.push_back(-1);
            badPoint.push_back(s.size());
            stack<char> stk;

            for(string::size_type i=0;i<s.size();i++)
            {
                if(s[i]=='(')
                {
                    stk.push('(');
                    indexStk.push(i);
                }
                else
                {
                    if(stk.empty())
                    {
                        badPoint.push_back(i);
                    }
                    else
                    {
                        if(stk.top()=='(')
                        {
                            stk.pop();
                            indexStk.pop();
                        }
                    }
                }
            }
            while(!indexStk.empty())
            {
                badPoint.push_back(indexStk.top());
                indexStk.pop();
            }

            sort(badPoint.begin(),badPoint.end());
            int result=0;
            for(size_t i=1;i<badPoint.size();i++)
            {
                result=max(badPoint[i]-badPoint[i-1]-1,result);
            }
            return result;
        }


        int longestValidParentheses(string s) {
            int N = s.size();
            if (N < 2)
                return 0;
            int res = 0;
            int k = 0, l = 0;
            for (int i = 0; i < N; i++) {
                if (s[i] == '(')
                    k++, l++;
                else
                    k--, l++;
                if (k == 0 && l > res)
                    res = l;
                else if (k < 0)
                    k = 0, l = 0;
            }

            k = 0, l = 0;
            for (int i = N - 1; i > 0; i--) {
                if (s[i] == ')')
                    k++, l++;
                else
                    k--, l++;
                if (k == 0 && l > res)
                    res = l;
                else if (k < 0)
                    k = 0, l = 0;
            }
            return res;
        }
};
