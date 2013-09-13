class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(s.empty())return 0;
            int result=1,last=1;
            for(int i=1;i!=s.size();i++)
            {
                int j=i-1;
                for(;j>=0&&s[j]!=s[i]&&i-last<=j;j--);
                last=i-j;
                result=max(i-j,result);
            }
            return result;  
        }
};
