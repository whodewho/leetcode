/*
    fibonacci. checked anson's, almost same, mine is better
   */
class Solution {
    public:
        int climbStairs(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int pre1=1,pre2=1;
            for(int i=2;i<=n;i++)
            {
                int tmp=pre1+pre2;
                pre1=pre2;
                pre2=tmp;
            }
            return pre2;
        }
};
