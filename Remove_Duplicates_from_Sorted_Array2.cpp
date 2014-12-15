//O(N)

class Solution {
    public:
        int removeDuplicates(int A[], int n) 
        {
            if(!n)return 0;
            int i=0;
            for(int j=1;j<n;j++)
            {
                if(A[i]!=A[j]||(i==0||(A[i-1]!=A[j])))A[++i]=A[j];
            }
            return i+1;
        }

        int removeAllDuplicats(int A[], int n)
        {
            if(!n)return 0;
            int i=0, k=-1;
            while(i<n)
            {
                int j=i+1;
                while(j<n&&A[j]==A[i])j++;
                if(j==i+1)k++;
                else i=j;
            }
            return k+1;
        }
};
