//O(N)
class Solution {
    public:

        int atoi(const char *str) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0, j = strlen(str) - 1;
            while (isspace(str[i]))
                i++;
            while (isspace(str[j]))
                j--;
            int sign = 1;

            if (str[i] == '+') {
                i++;
            } else if (str[i] == '-') {
                sign = -1;
                i++;
            }

            int result = 0, last = 0;
            while (i <= j) {
                if (!isdigit(str[i])) {
                    return result * sign;
                }
                result = (str[i] - '0') + last * 10;
                if (last != result / 10) {//overflow
                    if (sign == 1)
                        return INT_MAX;
                    else
                        return INT_MIN;
                }
                last = result;
                i++;
            }
            return result * sign;
        }
};
