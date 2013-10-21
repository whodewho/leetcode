/*
   better than anson's, maybe I met this problem half a year ago, now, I just can't remember
   findKth, awsome!always let a be the shorter array

   two pointer running, the second way, cool too

   the third, you may suffer, not quite well tested, but also good
 */

class Solution
{
    public:

        double findKth(int a[], int m, int b[], int n, int k)
        {
            //always assume that m is equal or smaller than n
            if (m > n)
                return findKth(b, n, a, m, k);
            if (m == 0)
                return b[k - 1];
            if (k == 1)
                return min(a[0], b[0]);
            //divide k into two parts
            int pa = min(k / 2, m), pb = k - pa;
            if (a[pa - 1] < b[pb - 1])
                return findKth(a + pa, m - pa, b, n, k - pa);
            else if (a[pa - 1] > b[pb - 1])
                return findKth(a, m, b + pb, n - pb, k - pb);
            else
                return a[pa - 1];
        }

        double findMedianSortedArrays(int A[], int m, int B[], int n)
        {
            int total = m + n;
            if (total & 0x1)
                return findKth(A, m, B, n, total / 2 + 1);
            else
                return (findKth(A, m, B, n, total / 2)
                        + findKth(A, m, B, n, total / 2 + 1)) / 2;
        }

        double findMedianSortedArrays1(int A[], int m, int B[], int n) {
            int i = 0, j = 0;
            int m1 = -1, m2 = -1;
            int s = (m + n) / 2;
            while (s >= 0) {
                int a = (i < m) ? A[i] : INT_MAX;
                int b = (j < n) ? B[j] : INT_MAX;
                m1 = m2;
                if (a < b) {
                    m2 = a;
                    i++;
                }
                else {
                    m2 = b;
                    j++;
                }
                s--;
            }
            if ((m + n) % 2 == 0) return (m1 + m2) / 2.0;
            return m2;
        };

        int findKthSmallest(int A[], int m, int B[], int n, int k) {
            assert(m >= 0); assert(n >= 0); assert(k > 0); assert(k <= m+n);

            int i = (int)((double)m / (m+n) * (k-1));
            int j = (k-1) - i;

            assert(i >= 0); assert(j >= 0); assert(i <= m); assert(j <= n);
            // invariant: i + j = k-1
            // Note: A[-1] = -INF and A[m] = +INF to maintain invariant
            int Ai_1 = ((i == 0) ? INT_MIN : A[i-1]);
            int Bj_1 = ((j == 0) ? INT_MIN : B[j-1]);
            int Ai   = ((i == m) ? INT_MAX : A[i]);
            int Bj   = ((j == n) ? INT_MAX : B[j]);

            if (Bj_1 < Ai && Ai < Bj)
                return Ai;
            else if (Ai_1 < Bj && Bj < Ai)
                return Bj;

            assert((Ai > Bj && Ai_1 > Bj) || 
                    (Ai < Bj && Ai < Bj_1));

            // if none of the cases above, then it is either:
            if (Ai < Bj)
                // exclude Ai and below portion
                // exclude Bj and above portion
                return findKthSmallest(A+i+1, m-i-1, B, j, k-i-1);
            else /* Bj < Ai */
                // exclude Ai and above portion
                // exclude Bj and below portion
                return findKthSmallest(A, i, B+j+1, n-j-1, k-j-1);
        }
};
