//O(N)
class Solution {
    public:
        bool isPalindrome(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i=0,j=s.length()-1;
            while(i<j)
            {
                if(!isalnum(s[i]))
                {
                    i++;
                    continue;
                }
                else if(!isalnum(s[j]))
                {
                    j--;
                    continue;
                }
                else if(tolower(s[i])!=tolower(s[j]))
                {
                    return false;
                }
                i++;
                j--;
            }
            return true;
        }
};
