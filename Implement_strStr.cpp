class Solution {
    public:
        char *strStr(char *haystack, char *needle) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(*needle=='\0')return haystack;
            while(*haystack)
            {
                if(*haystack==*needle)
                {
                    int i=0;
                    while(*(haystack+i)!='\0'&&*(needle+i)!='\0'&&*(haystack+i)==*(needle+i))
                    {
                        i++;
                    }
                    if(*(needle+i)=='\0')return haystack;
                    if (*(haystack + i) == '\0')return NULL;
                }
                haystack++;
            }
            return NULL;
        }
};
