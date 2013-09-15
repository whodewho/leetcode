//http://blog.csdn.net/hopeztm/article/details/7992253
/*
    c* means "" or "cccc..."
    not "c" or "cccc...." 
    * match 0 or more preceding...I didn't get it until one minute ago
   */
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
};