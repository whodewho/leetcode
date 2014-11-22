/*
    second is anson's, his is better
*/
class Solution {
    public:

        int search(int A[], int n, int target) {
            int l = 0, u = n - 1;
            while (l <= u) {
                int m = l + (u - l) / 2;
                if (A[m] == target) return m;
                if (A[m] >= A[l]) {
                    if (A[l] <= target && target < A[m]) u = m - 1;
                    else l = m + 1;
                }
                else {
                    if (A[m] < target && target <= A[u]) l = m + 1;
                    else u = m - 1;
                }

            }
            return -1;
        }
};
