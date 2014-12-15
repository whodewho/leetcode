//O(N)

class Solution {
    public:
        int singleNumber(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int ones=0,twos=0;
            int common_bits=0;
            for(int i=0;i<n;i++)
            {
                //appear more than 1, means 2 and 3, go to two
                twos=twos|(ones&A[i]);
                //appear odd time, means 1 and 3, go to one
                ones=ones^A[i];
                //appear in 3 times, get ~, update two and one
                common_bits=~(twos&ones);
                ones=ones&common_bits;
                twos=twos&common_bits;
            }
            return ones;
        }
};
