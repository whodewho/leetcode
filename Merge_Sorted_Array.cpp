/*
    start from the end. i save one line of code than anson's.
   */
class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int l=m+n-1,i=m-1,j=n-1;
            while(i>=0&&j>=0)
            {
                if(A[i]>=B[j])A[l--]=A[i--];
                else A[l--]=B[j--];
            }
            while(j>=0)A[l--]=B[j--];
        }
};
