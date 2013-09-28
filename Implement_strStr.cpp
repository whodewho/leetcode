/*
   the second, kmp
 */
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


        void compute_prefix(char* p, int m, vector<int>& pr) {
            pr[0]=-1;
            int k = -1;  
            for(int i  = 1; i < m; i++)  
            {  
                while(k > -1 && p[k+1] != p[i]) k = pr[k];  
                if(p[k+1] == p[i]) k = k+1;  
                pr[i] = k;  
            }  
        }

        char *strStr(char *haystack, char *needle) 
        {
            int n=strlen(haystack);
            int m=strlen(needle);
            vector<int> pr(m+1);
            if(m==0)return haystack;

            compute_prefix(needle,m,pr);

            int j=-1;
            for(int i=0;i<n;i++)
            {
                while(j>-1&&needle[j+1]!=haystack[i])j=pr[j];
                if(needle[j+1]==haystack[i])j=j+1;
                if(j==m-1)
                {
                    return haystack+i-m+1;
                }
            }
            return NULL;
        }
};
