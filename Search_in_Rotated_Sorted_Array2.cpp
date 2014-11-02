/*
    O(log(N)) -> O(N)
 */
class Solution {
    public:

        bool search(int A[], int n, int target) {

            // Note: The Solution object is instantiated only once and is reused by each test case.
            int l = 0, u = n - 1;
            while (l <= u) {
                int m = l + (u - l) / 2;
                if (A[m] == target) return 1;
                if(A[l]==A[u])
                {
                    l++;
                    continue;
                }

                if (A[m] >= A[l]) {
                    if (A[l] <= target && target < A[m]) u = m - 1;
                    else l = m + 1;
                }
                else {
                    if (A[m] < target && target <= A[u]) l = m + 1;
                    else u = m - 1;
                }
            }
            return 0;
        }
};
