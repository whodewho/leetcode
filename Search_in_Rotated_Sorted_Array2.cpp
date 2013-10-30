/*
   find the reset point first, then two binary search(in fact, one, if)
   the second is anson's, linear time, but is faster than mine log(n)... 

   third one, second try, better
 */
class Solution {
    public:

        bool search(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int reset = 0;
            int l = 0, h = n - 1;
            while (l <= h) {
                int m = (l + h) / 2;
                if (m == l) {
                    reset = A[l] >= A[h] ? l : h;
                    break;
                }
                if (A[l] == A[m]) {
                    l++;
                } else if (A[l] > A[m]) {
                    h = m - 1;
                } else if (A[l] < A[m]) {
                    l = m ;
                }
            }

            int i = 1;
            while (reset + i < n && A[reset] == A[reset + i]) {
                i++;
            }
            reset = reset + i - 1;

            l = 0, h = reset;
            while (l <= h) {
                int m = (l + h) / 2;
                if (target == A[m])
                    return true;
                if (target < A[m]) {
                    h = m - 1;
                } else if (target > A[m]) {
                    l = m + 1;
                }
            }
            l = reset + 1, h = n - 1;
            while (l <= h) {
                int m = (l + h) / 2;
                if (target == A[m])
                    return true;
                if (target < A[m]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
            return false;
        }


        bool search(int A[], int n, int target) {
            for (int i = 0; i < n; i++) {
                if (A[i] == target) return true;
            }
            return false;
        }

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
