/*
    O(n)
    0011xxxx2
    low=2 mid=4 high=7
   */
class Solution {
    public:
        void sortColors(int A[], int n) {
            int low = 0,mid = 0,high = n - 1;
            if(n <= 1) return;
            while (mid <= high) {
                if (A[mid] == 0) {
                    A[mid++] = A[low];
                    A[low++] = 0;
                }
                else if(A[mid] == 1) {
                    mid++;
                }
                else if (A[mid] == 2) {
                    A[mid] = A[high];
                    A[high--] = 2;
                }
            }
        }
};
