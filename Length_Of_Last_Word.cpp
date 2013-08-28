/*
   the second is anson's, his is better
   book, letter, code, I am never alone
 */
class Solution {
    public:
        int lengthOfLastWord(const char *s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int num=0,i=0;
            bool space=false;
            while(s[i]!='\0')
            {
                if(s[i]==' ')
                {
                    space=true;
                }
                else
                {
                    if(space)
                    {
                        num=1;
                        space=false;
                    }
                    else
                    {
                        num++;
                    }
                }
                i++;
            }
            return num;
        }

        int lengthOfLastWord(const char *s) {
            int N = strlen(s);
            if (N == 0) return 0;
            int end = N - 1;
            while (end >= 0 && s[end] == ' ') end--;
            if (end < 0) return 0;
            int start = end - 1;
            while (start >= 0 && s[start] != ' ') start--;
            return end - start;
        }
};
