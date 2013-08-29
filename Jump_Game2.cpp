/*
   the second exceed time limits, you know why
   the third is anson's, his is better, anson dislike space consume
   he extend the area covered every time, good job,return the time is ok
 */
class Solution {
    public:
        int jump(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int *p = (int*) malloc(sizeof(int) * n);
            fill(p,p+n,n);
            p[0] = 0;
            for (int i = 0; i < n-1; i++) {
                for (int k = A[i]; k >= 1; k--) {
                    if (k + i >= n - 1)
                        return p[i] + 1;
                    p[i + k] = min(p[i + k], p[i] + 1);
                    if(i+k+A[i+k]>=n-1)return p[i+k]+1;
                }
            }
            return p[n - 1];
        }

        int jump(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int *p = (int*) malloc(sizeof(int) * n);
            memset(p, n, n);
            p[n - 1] = 0;
            for (int j = n - 2; j >= 0; j--) {
                int minD = n;
                for (int k = A[j]; k >= 1; k--) {
                    if (k + j >= n - 1) {
                        minD = 1;
                        break;
                    }
                    minD = min(minD, p[k + j] + 1);
                }
                p[j] = minD;
            }
            return p[0];
        }

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
