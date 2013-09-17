class Solution {
    public:
        int search(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int l=0,h=n-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(A[mid]==target)return mid;
                if(A[l]<=A[h])
                {
                    if(target<A[mid])h=mid-1;
                    else if(target>A[mid])l=mid+1;
                }
                else
                {
                    if(A[l]<=A[mid])
                    {
                        if(target>=A[l]&&target<A[mid])h=mid-1;
                        else l=mid+1;
                    }
                    else
                    {
                        if(target>=A[mid]&&target<A[l])l=mid+1;
                        else h=mid-1;
                    }
                }
            }   
            return -1;
        }
};
