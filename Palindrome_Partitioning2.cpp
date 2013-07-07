/*
    The recursion can work, but not effecient. Dynamic planning can do better. 
    dp[i][j] will record whether substr(i,j) is palindrome.
    dp2[i] will record the min cut of substr(0,j).
    Now ,the question is if we have get dp2[0...i], how do we get dp2[i+1]?
    dp2[i+1] is initialized with dp2[i]+1, apparaently.
    for every k in (0...i), if substr(j,i+1) is palindrome, we can get an alternative cuting method, its dp2[j]+1,substr(j,i+1)
   */
class Solution {
    public:
        int minCut(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(s.size()==0)
                return 0;
            int N=s.size();
            vector<vector<bool>> dp(N,vector<bool>(N,false));

            for(int i=N-1;i>=0;i--)
            {
                for(int j=i;j<N;j++)
                {
                    if(i==j)dp[i][j]=true;
                    else if(i+1==j)dp[i][j]=(s[i]==s[j]);
                    else    dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
                }
            }

            vector<int> dp2(N+1,0);
            dp2[0]=-1;
            for(int i=2;i<=N;i++)
            {
                dp2[i]=dp2[i-1]+1;
                for(int j=i-2;j>=0;j--)
                {
                    if(dp[j][i-1])
                        dp2[i]=min(dp2[i],dp2[j]+1);
                }
            }
            return dp2[N];
        }
/*
        bool isPalindrome(string s)
        {
            int i=0,j=s.size()-1;
            while(i<j)
            {
                if(s[i++]!=s[j--])
                    return false;
            }
            return true;
        }

        int minCut(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(s.size()<=1||isPalindrome(s))
            {
                return 0;
            }

            int min=s.size()-1;
            for(int i=1;i<s.size();i++)
            {            
                int minHeadCut=0;
                string head=s.substr(0,i);
                minHeadCut=minCut(head);

                if(minHeadCut+1>=min)
                {
                    continue;
                }

                int minTailCut=0;
                string tail=s.substr(i,s.size()-i);
                minTailCut=minCut(tail);

                if(minHeadCut+1+minTailCut<min)
                {
                    min=minHeadCut+1+minTailCut;
                }
            }
            return min;
        }
*/
};
