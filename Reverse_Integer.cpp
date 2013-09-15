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
                result=result*10+x%10;
                x=x/10;
            }
            return sign*result;
        }
};
