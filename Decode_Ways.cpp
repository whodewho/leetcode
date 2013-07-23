/*
    i checked anson's solution. same idea, mine is better.
   */
class Solution {
    public:
        int numDecodings(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(s.size()==0)return 0;
            int N=s.size();
            vector<int> res(N+1,0);
            res[0]=1;
            if(s[0]!='0')res[1]=1;
            else return 0;

            for(int i=2;i<N+1;i++)
            {
                string str=s.substr(i-2,2);
                int tmp=atoi(str.c_str());
                if(str[1]!='0')
                {
                    res[i]+=res[i-1];
                    if(tmp>=10&&tmp<=26)
                    {
                        res[i]+=res[i-2];
                    }
                }
                else{
                    if(tmp==10||tmp==20) res[i]+=res[i-2];
                    else return 0;
                }

            }
            return res[N];
        }
};
