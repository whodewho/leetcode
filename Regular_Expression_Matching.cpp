//http://blog.csdn.net/hopeztm/article/details/7992253
/*
   c* means "" or "cccc..."
   not "c" or "cccc...." 
   match 0 or more preceding...I didn't get it until one minute ago

   every recursion way has a iteration alteration
http://discuss.leetcode.com/questions/175/regular-expression-matching
*/

//O(M^N)

//O(M*N)

class Solution {
    public:
        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    

            if( 0 == *p) return 0 == *s;
            
            if(*(p+1) != '*')
            {
                if(*p == *s || (*p) == '.' && (*s) != 0)
                {
                    return isMatch(s+1, p+1);
                }
                return false;
            }
            else
            {
                while(*p == *s || ((*p) == '.' && (*s) != 0))
                {
                    if(isMatch(s, p + 2))
                    {
                        return true;
                    }
                    s++;
                }
                return isMatch(s, p + 2);
            }
        }


        bool isMatch(const char *s, const char *p) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (!s || !p)
                return false;

            int slen = strlen(s);
            int plen = strlen(p);
            vector<vector<bool> > dp(plen + 1, vector<bool>(slen + 1, false));

            dp[0][0] = true;
            for (int i = 1; i <= plen; i++) {
              if(p[i-1] == '*') {
                  dp[i][0] = i > 1 ? dp[i - 2][0] : false;
                  if (i < 2)
                      continue;
                  if (p[i - 2] != '.') {
                      //*号不用,dp[i-1][j]，匹配1个
                      //'p[i-2]*'不用,i>=2 && dp[i-2][j], 匹配0
                      //'p[i-2]*'用上,j>=2 dp[i][j-1]&&s[j-1]==s[j-2]&&s[j-2]==p[i-2], so complicated，匹配>1个
                      for (int j = 1; j <= slen; j++) {
                        if (dp[i - 1][j] 
                          || (i >= 2 && dp[i - 2][j])
                          || (j >= 2 && dp[i][j - 1] && s[j - 1] == s[j - 2] && s[j - 2] == p[i - 2]))
                          dp[i][j] = true;  
                      }
                  } else {
                      int j = 1;
                      // '.'首次匹配后的所有位置都能配上
                      while (!dp[i - 2][j] && j <= slen && !dp[i - 1][j])
                          j++;
                      for (; j <= slen; j++) {
                          dp[i][j] = true;
                      }
                  }
              }
              else {
               for (int j = 1; j <= slen; j++) {
                   if (dp[i - 1][j - 1]
                           && (s[j - 1] == p[i - 1] || p[i - 1] == '.'))
                       //本列匹配，且i-1,j-1前都匹配
                       dp[i][j] = true;
               }
              }
          }
          return dp[plen][slen];
        }
};
