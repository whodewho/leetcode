/*
O(N)
 */
class Solution {
    public:

        int lengthOfLastWord(const char *s) {
            int N = strlen(s);
            if (N == 0) return 0;
            int end = N - 1;
            while (end >= 0 && s[end] == ' ') end--;
            if (end < 0) return 0;
            int start = end - 1;
            while (start >= 0 && s[start] != ' ') start--;
            return end - start;
        }
};
