/*
    reverse cantor.
   */
class Solution {
    public:
        string getPermutation(int n, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int factor[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 }; //阶乘
            char st[9] = { 0 };

            int visit[10] = { 0 };
            int t;
            int x = k - 1;
            for (int i = 0; i < n; i++) {
                t = x / factor[n - i - 1];
                x %= factor[n - i - 1];
                for (int j = 0; j <= t; j++)
                    if (visit[j] == 1)
                        t++;
                visit[t] = 1;
                st[i] = '0'+t + 1;
            }

            string str(st, st + n);
            return str;
        }
};
