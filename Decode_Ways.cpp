/*
O(N)
O(N)
 */
class Solution {
    public:

        int numDecodings(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m=s.size();
            if(m==0)return 0;

            vector<int> num(m,0);
            num[0]=s[0]!='0';

            for(string::size_type i=1;i<m;i++)
            {
                if(s[i]!='0')
                {
                    num[i]+=num[i-1];
                }

                if(s[i-1]=='1'||s[i-1]=='2'&&s[i]<='6')
                    if(i==1)num[i]+=1;
                    else num[i]+=num[i-2];
            }

            return num[m-1];
        }
};
