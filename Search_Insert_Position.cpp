//O(log(N))

class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int l=0,h=n-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(A[mid]<target)
                {
                    l=mid+1;
                }
                else if(A[mid]>target)
                {
                    h=mid-1;
                }
                else
                {
                    return mid;
                }
            }

            return h+1;
        }
};
