class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!n)return 0;
            int i=0,j=1;
            for(;j<n;j++)
            {
                if(A[j]!=A[i])
                {
                    A[++i]=A[j];
                }
            }
            return i+1;
        }
};
