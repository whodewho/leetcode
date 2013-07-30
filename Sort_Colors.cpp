/*
    O(2n) and O(n)
    0011xxxx2
    low=2 mid=4 high=7
   */
class Solution {
    public:
        void sortColors(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int red=0,white=0,blue=0;
            for(int i=0;i<n;i++)
            {
                if(A[i]==0)red++;
                else if(A[i]==1)white++;
                else if(A[i]==2)blue++;
            }
            for(int i=0;i<n;i++)
            {
                if(red)A[i]=0,red--;
                else if(white)A[i]=1,white--;
                else if(blue)A[i]=2,blue--;
            }

        }

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
