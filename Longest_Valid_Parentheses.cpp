/*
O(N)
*/
class Solution {
    public:
        int longestValidParentheses(string s) {
            int N = s.size();
            if (N < 2)
                return 0;
            int res = 0;
            int k = 0, l = 0;
            for (int i = 0; i < N; i++) {
                if (s[i] == '(')
                {
                    k++;
                    l++;
                }
                else
                {
                    k--;
                    l++;
                }
                if (k == 0 && l > res)
                    res = l;
                else if (k < 0)
                    k = 0, l = 0;
            }

            k = 0, l = 0;
            for (int i = N - 1; i > 0; i--) {
                if (s[i] == ')')
                {
                    k++;
                    l++;
                }
                else
                {
                    k--;
                    l++;
                }
                if (k == 0 && l > res)
                    res = l;
                else if (k < 0)
                    k = 0, l = 0;
            }
            return res;
        }

        int longestValidParentheses(string s) {
            int n=s.size();
            vector<int> valid(n, 0);
            stack<int> index;
            for(int i=0;i<s.size();i++)
            {
                if(index.empty())
                {
                    index.push(i);
                }
                else
                {
                    if(s[index.top()]=='('&&s[i]==')')
                    {
                        valid[index.top()]=1;
                        valid[i]=1;
                        index.pop();
                    }
                    else
                    {
                        index.push(i);
                    }
                }
            }
            
            int length=0,i=0;
            for(int j=0;j<n;j++)
            {
                if(valid[j])i++;
                else
                {
                    length=max(length, i);
                    i=0;
                }
            }
            length=max(length, i);
            return length;
        }
};
