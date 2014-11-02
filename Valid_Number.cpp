/*
O(N)
 */
class Solution {
    public:

        bool isNumber(const char* s) {
            // trim leading/trailing spaces
            while (*s != '\0' && isspace(*s)) s++;
            if (*s == '\0') return false;
            const char *e = s + strlen(s) - 1;
            while (e > s && isspace(*e)) e--;
            // skip leading +/-
            if (*s == '+' || *s == '-') s++;

            bool num = false; // is a digit
            bool dot = false; // is a '.'
            bool exp = false; // is a 'e'
            while (s != e + 1) {
                if (*s >= '0' && *s <= '9') {
                    num = true;
                }
                else if (*s == '.') {
                    if(exp || dot) return false;
                    dot = true;
                }
                else if (*s == 'e') {
                    if(exp || num == false) return false;
                    exp = true;
                    num = false;
                }
                else if (*s == '+' || *s == '-') {
                    if (*(s-1) != 'e') return false;
                }
                else {
                    return false;
                }
                s++;
            }
            return num;
        }
};
