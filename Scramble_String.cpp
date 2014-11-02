/*
   F(N)=(F(1)+F(N-1) + F(2)+F(N-2) + ... + F(N-1)+F(1))
       =2*(F(1)+F(2) ... + F(N-1))
       =O(2^N)

    O(N^4)
   */
class Solution {
    public:
        bool isScramble(string s1, string s2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(s1.size()!=s2.size())return false;
            if(!isSameAlpha(s1,s2))return false;
            if(s1.size()==1)return true;

            int N=s1.size();
            for(int i=0;i<N-1;i++)
            {
                bool sign1=false;
                if(isSameAlpha(s1.substr(0,i+1),s2.substr(0,i+1)))
                {
                    sign1=isScramble(s1.substr(0,i+1),s2.substr(0,i+1))
                        &&
                        isScramble(s1.substr(i+1,N-i-1),s2.substr(i+1,N-i-1));
                }
                if(sign1)return true;
                if(isSameAlpha(s1.substr(0,i+1),s2.substr(N-i-1,i+1)))
                {
                    return isScramble(s1.substr(0,i+1),s2.substr(N-i-1,i+1))
                        &&
                        isScramble(s1.substr(i+1,N-i-1),s2.substr(0,N-i-1));
                }
            }
            return false;
        }

        bool isSameAlpha(string s1,string s2)
        {
            vector<int> counts(26,0);
            for(int i=0;i<s1.size();i++)
            {
                counts[s1[i]-'a']++;
                counts[s2[i]-'a']--;
            }
            for(int i=0;i<26;i++)
            {
                if(counts[i])return false;
            }
            return true;
        }

        bool isScramble(string s1, string s2) {
            int len=s1.size();
            bool dp[100][100][100]={false};
            for (int i=len-1;i>=0;i--)
                for (int j=len-1;j>=0;j--) {
                    dp[i][j][1]=(s1[i]==s2[j]);
                    for (int l=2;i+l<=len && j+l<=len;l++) {
                        for (int n=1;n<l;n++) {
                            dp[i][j][l]|=dp[i][j][n]&&dp[i+n][j+n][l-n];
                            dp[i][j][l]|=dp[i][j+l-n][n]&&dp[i+n][j][l-n];
                        }
                    }
                }
            return dp[0][0][len];
        }
};
