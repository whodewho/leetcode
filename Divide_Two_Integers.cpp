/*

*/
class Solution {
    public:
        int divide(int dividend, int divisor) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int sign =
                (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0) ? 1 : -1;

            int result = 0;

            if (dividend == INT_MIN && divisor == INT_MIN) {
                return 1;
            } else if (dividend == INT_MIN) {
                dividend -= divisor;
                result++;
            } else if (divisor == INT_MIN) {
                return 0;
            }

            dividend = abs(dividend);
            divisor = abs(divisor);
            if (divisor == 1)
                return sign * (dividend+result);
            if (dividend < divisor)
                return sign*result;

            while (dividend >= divisor) {
                int i = 1;
                while ((int) (pow(divisor, i) > 0)
                        && (int) (pow(divisor, i) <= dividend)) {
                    i++;
                }
            
                i--;
                dividend = (int) (dividend - pow(divisor, i));
                result += pow(divisor, i - 1);
            }

            return sign * result;
        }
};
