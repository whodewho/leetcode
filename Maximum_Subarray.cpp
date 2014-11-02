/*
   O(N)
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
                maxAll=max(maxCurr, maxAll);
            }
            return maxAll;
        }

};
