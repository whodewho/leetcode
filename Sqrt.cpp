/*
log(N)
 */
class Solution {
    public:
        int sqrt(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i=pow(2,log(x)/log(2)/2);
            while (i * i <= x && i * i >= 0)
                i++;
            i--;
            return i;
        }

        int sqrt(int x) {
            if(x < 2) return x;
            long long l = 0;
            long long u = 1 + (x / 2);
            while(l + 1 < u) {
                long long m = l + (u - l) / 2;
                long long p = m * m;
                if(p > x)
                    u = m;
                else if(p < x)
                    l = m;
                else
                    return m;
            }
            return (int)l;
        }
};
