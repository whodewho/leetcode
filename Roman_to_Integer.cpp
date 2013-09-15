/*
    the second is anson's
   */
class Solution {
    public:
        int romanToInt(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            map<char,int> dict;
            dict['I']=1;
            dict['V']=5;
            dict['X']=10;
            dict['L']=50;
            dict['C']=100;
            dict['D']=500;
            dict['M']=1000;
            int result=0;
            for(string::size_type i=0;i!=s.size();i++)
            {
                if(s[i]=='I')
                {
                    if(i+1!=s.size()&&(s[i+1]=='V'||s[i+1]=='X'))
                    {
                        result-=1;
                        continue;
                    }
                }
                else if(s[i]=='X')
                {
                    if(i+1!=s.size()&&(s[i+1]=='L'||s[i+1]=='C'))
                    {
                        result-=10;
                        continue;
                    }
                }
                else if(s[i]=='C')
                {
                    if(i+1!=s.size()&&(s[i+1]=='D'||s[i+1]=='M'))
                    {
                        result-=100;
                        continue;
                    }
                }
                result+=dict[s[i]];
            }
            return result;
        }

        map<char, int> dict;
        int romanToInt(string s) {
            dict['M'] = 1000;
            dict['D'] = 500;
            dict['C'] = 100;
            dict['L'] = 50;
            dict['X'] = 10;
            dict['V'] = 5;
            dict['I'] = 1;
            int res = 0;
            size_t i = 0;
            while (i < s.size() - 1) {
                if (dict[s[i]] < dict[s[i+1]]) res -= dict[s[i]];
                else res += dict[s[i]];
                i++;
            }
            res += dict[s[i]];
            return res;
        }
};
