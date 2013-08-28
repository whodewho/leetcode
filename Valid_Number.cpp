/*
   the second is anson's, mine is bad, no, shit
 */
class Solution {
    public:

        bool isNumber(const char *s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0;
            bool sign = true;
            bool point = false;
            bool digit = false;
            while (s[i] != '\0' && s[i] == ' ') {
                i++;
            }
            if (s[i] == '+' || s[i] == '-')
                i++;
            while (s[i] != '\0') {
                if (isdigit(s[i])) {
                    digit = true;
                    i++;
                    continue;
                } else {
                    if (s[i] == ' ') {
                        bool tmp = true;
                        for (int k = i + 1; s[k] != '\0'; k++) {
                            if (s[k] != s[i]) {
                                tmp = false;
                                break;
                            }
                        }
                        return tmp;
                    }
                    if (s[i] == '.') {
                        if(!digit&&!isdigit(s[i+1]))return false;
                        if (!point) {
                            i++;
                            point = true;
                            continue;
                        } else {
                            sign = false;
                            break;
                        }
                    }
                    if (s[i] != 'e') {
                        sign = false;
                        break;
                    } else {
                        if (!digit)
                            return false;
                        bool space = false;
                        int k = i + 1;
                        if (s[k] == '+' || s[k] == '-')
                            k++;
                        bool tmpDigit = false;
                        for (; s[k] != '\0'; k++) {
                            if (!isdigit(s[k])) {
                                if (s[k] == ' ') {
                                    space = true;
                                    break;
                                } else {
                                    return false;
                                }
                            } else {
                                tmpDigit = true;
                            }
                        }
                        if (space) {
                            for (int t = k + 1; s[t] != '\0'; t++) {
                                if (s[t] != s[k])
                                    return false;
                            }
                        }
                        return tmpDigit;
                    }
                }
            }

            return digit && sign;
        }


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
