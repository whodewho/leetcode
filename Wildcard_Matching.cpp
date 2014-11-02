/*
   from http://discuss.leetcode.com/questions/222/wildcard-matching
   what's the difference with regression_match below?
   here isMatch("aab","c*a*b") true
   below false, the "*" is different

   http://blog.csdn.net/linhuanmars/article/details/21198049
 */

//O(M*N)

class Solution {
    public:

      bool isMatch(const char *s, const char *p)
      {
        int m=strlen(s);
        int n=strlen(p);
        vector<bool> dp(m+1);
        dp[0]=true;
        for(int j=0;j<n;j++)
        {
          if(p[j]!='*')
          {
            for(int i=m-1;i>=0;i--)
              dp[i+1]=dp[i]&&(p[j]=='?'||s[i]==p[j]);
              //dp[i]以为这dp[j-1][i]匹配成功了
          }
          else
          {
            int i=0;
            while(i<=m&&!dp[i])i++;
            for(;i<=m;i++)
              dp[i]=true;
          }
          dp[0]=dp[0]&&p[j]=='*';
        }
        return dp[m];
      }

      
      bool isMatch(const char *s, const char *p) {
          // Start typing your C/C++ solution below
          // DO NOT write int main() function
          if(!s && !p) return true;

          const char *star_p=NULL,*star_s=NULL;

          while(*s)
          {
              if(*p == '?' || *p == *s)
              {
                  ++p;
                  ++s;
              }
              else if(*p == '*')
              {
                  //skip all continuous '*'
                  while(*p == '*') ++p;
                  if(!*p) return true; //if end with '*', its match.

                  star_p = p; //store '*' pos for string and pattern
                  star_s = s;
              }
              else if((!*p || *p != *s)  && star_p)
              {
                  s = ++star_s; //skip non-match char of string, regard it matched in '*'
                  p = star_p; //pattern backtrace to later char of '*'
              }
              else return false;
          }

          //check if later part of p are all '*'
          while(*p)
              if(*p++ != '*')
                  return false;

          return true;
      }
}