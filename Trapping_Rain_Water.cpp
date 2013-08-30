/*
    from anson, need some rest
    think vertically, not horizonly
   */
class Solution {
    public:

        int trap(int A[], int n) {
            if (n <= 2)
                return 0;
            int lmax[n];
            int rmax[n];
            lmax[0] = A[0];
            for (int i = 1; i < n; i++) {
                lmax[i] = max(lmax[i - 1], A[i]);
            }
            rmax[n - 1] = A[n - 1];
            for (int i = n - 2; i >= 0; i--) {
                rmax[i] = max(rmax[i + 1], A[i]);
            }
            int total = 0;
            for (int i = 1; i < n - 1; i++) {
                int low = min(lmax[i - 1], rmax[i + 1]);
                total += (low > A[i]) ? (low - A[i]) : 0;
            }
            return total;
        }
};
