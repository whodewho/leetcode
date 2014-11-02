/*
O(N)
   */
class Solution {
    public:
        bool canJump(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0;
            int next = 0;
            while (i <= next) {
                next = max(next, i + A[i]);
                if (next >= n - 1) return true;
                i++;
            }
            return false;
        }
};
