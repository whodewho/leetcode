/*
    the first, time limit exceed
    the second, same as the first
    the third, anson's code, perfect
    what's the difference with regression_match below, cover and equal? i don't see it
    ambigurous.
   */
class Solution {
    public:
        bool isMatch(const char* s, const char* p) {
            int i = 0, j = 0;
            while (s[i] != '\0' && p[j] != '\0') {
                if (s[i] == p[j] || p[j] == '?') {
                    i++;
                    j++;
                } else if (p[j] == '*') {
                    return isMatch(s + i + 1, p + j + 1) || isMatch(s + i + 1, p + j)
                        || isMatch(s + i, p + j + 1);
                } else {
                    break;
                }
            }
            if (s[i] == '\0') {
                while (p[j] == '*') {
                    j++;
                }
                if (p[j] == '\0') {
                    return true;
                }
            }
            return false;
        }

        bool worker(const char* s, int i1, int j1, const char* p, int i2, int j2) {
            if (i1 > j1 && i2 > j2)
                return true;

            int t1 = -1, t2 = -1;
            for (int k = i2; k <= j2; k++) {
                if (p[k] == '*' || p[k] == '?') {
                    if (t1 == -1)
                        continue;
                    else
                        break;
                } else {
                    if (t1 == -1)
                        t1 = k;
                    t2 = k;
                }
            }

            if (t1 == -1) {
                int c = 0;
                bool sign = false;
                for (int k = i2; k <= j2; k++) {
                    if (p[k] == '?')
                        c++;
                    else if (p[k] == '*')
                        sign = true;
                }
                if (c == j1 - i1 + 1)
                    return true;
                else if (c < j1 - i1 + 1)
                    return sign;
                else
                    return false;
            }

            for (int k = i1; k <= j1; k++) {
                if (s[k] == p[t1]) {
                    int h = 0;
                    while (h < t2 - t1 + 1 && s[k + h] == p[t1 + h]) {
                        h++;
                    }
                    if (h == t2 - t1 + 1) {
                        /*
                           for (int b = i1; b <= k - 1; b++)
                           cout << s[b];
                           cout << " ";
                           for (int b = 0; b < h; b++)
                           cout << s[k + b];
                           cout << " ";
                           for (int b = k + h; b <= j1; b++)
                           cout << s[b];
                           cout << endl;

                           for (int b = i2; b <= t1 - 1; b++)
                           cout << p[b];
                           cout << " ";
                           for (int b = t1; b <= t2; b++)
                           cout << p[b];
                           cout << " ";
                           for (int b = t2 + 1; b <= j2; b++)
                           cout << p[b];
                           cout << endl;
                           cout << endl;
                         */
                        if (worker(s, i1, k - 1, p, i2, t1 - 1)
                                && worker(s, k + h, j1, p, t2 + 1, j2)) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        bool isMatch1(const char* s, const char* p) {
            int m = strlen(s) - 1;
            int n = strlen(p) - 1;
            return worker(s, 0, m, p, 0, n);
        }

        bool isMatch2(const char* s, const char* p) {
            const char *ps, *pp;
            bool star = false;
loopStart: for (ps = s, pp = p; *ps; ++ps, ++pp) {
               switch (*pp) {
                   case '?':
                       break;
                   case '*':
                       star = true;
                       s = ps, p = pp + 1;
                       if (!*p)
                           return true;
                       goto loopStart;
                   default:
                       if (*ps != *pp)
                           goto starCheck;
                       break;
               }
           }
           while (*pp == '*')
               ++pp;
           return (!*pp);
starCheck: if (!star)
               return false;
           s++;
           goto loopStart;
           return false;
        }}
