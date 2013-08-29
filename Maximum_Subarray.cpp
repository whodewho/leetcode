/*
    i do not see divide and conque a cool(subtle) solution
    checked anson's code... he list all the solution from n*n*n to n, is that funny
   */
class Solution {
    public:
        int maxSubArray(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int maxAll=INT_MIN,maxCurr=0;
            for(int i=0;i<n;i++)
            {
                maxCurr=maxCurr>=0?maxCurr+A[i]:A[i];
                maxAll=maxCurr>maxAll?maxCurr:maxAll;
            }
            return maxAll;
        }

        int worker(int A[],int left,int right)
        {
            if(left==right)return A[left];
            int mid=(left+right)>>1;
            int leftSum=INT_MIN,leftTmp=0,rightSum=INT_MIN,rightTmp=0;
            for(int i=mid;i>=left;i--)
            {
                leftTmp+=A[i];
                leftSum=leftTmp>leftSum?leftTmp:leftSum;
            }
            for(int j=mid+1;j<=right;j++)
            {
                rightTmp+=A[j];
                rightSum=rightTmp>rightSum?rightTmp:rightSum;
            }

            int maxL=leftSum+rightSum,maxR=maxL,maxM=maxL;
            if(mid>=left)
                maxL=worker(A,left,mid);
            if(right>=mid+1)
                maxR=worker(A,mid+1,right);

            return max(maxL,max(maxR,maxM));
        }

        int maxSubArray(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function

            return worker(A,0,n-1);
        }
};
