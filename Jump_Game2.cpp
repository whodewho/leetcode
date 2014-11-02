/*
O(N)
 */
class Solution {
    public:

        int jump(int A[], int n) {
            int step = 0;
            int start = 0;
            int end = 0;
            int next = 0;
            while (end < n - 1) {
                step++;
                for (int i = start; i <= end; i++)
                    next = max(next, A[i] + i);
                start = end + 1;
                //if (next <= end)
                //return -1;
                end = next;
            }
            return step;
        }

};
