class Solution {
    public:
        vector<int> searchRange(int A[], int n, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> result(2,-1);
            int l=0,h=n-1;

            while(l<=h)
            {
                int mid=(l+h)/2;
                if(target<A[mid])h=mid-1;
                else if(target>A[mid])l=mid+1;
                else
                {
                    h=mid-1;
                    result[0]=mid;
                }
            }

            l=0,h=n-1;
            while(l<=h)
            {
                int mid=(l+h)/2;
                if(target<A[mid])h=mid-1;
                else if(target>A[mid])l=mid+1;
                else
                {
                    l=mid+1;
                    result[1]=mid;
                }
            }

            return result;
        }
};
