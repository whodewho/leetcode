//O(N)

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(n<=1)return n;
            int count=0,k=0;
            for(int i=1;i<n;i++)
            {
                if(A[i]==A[k])
                {
                    if(count<1)
                    {
                        count++;
                        A[++k]=A[i];
                    }
                }
                else
                {
                    A[++k]=A[i];
                    count=0;
                }
            }
            for(int j=k+1;j<n;j++)
            {
                A[j]='\0';
            }
            return k+1;
        }
};
