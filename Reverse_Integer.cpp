//overflow,
class Solution {
    public:
        int reverse(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int sign = x >= 0 ? 1 : -1;
            x = abs(x);
            int result=0;
            while(x)
            {
                int tmp=result*10+x%10;
                if(tmp/10!=result)return 0;
                result=tmp;
                x=x/10;
            }   
            return sign*result;
        }

        int reverse(int x) {
            int sign=1;
            if(x<0)sign=-1;
            string s=to_string(abs(x));
            std::reverse(s.begin(), s.end());
            return sign*atoi(s.c_str());
        }
};