class Solution {
    public:
        int singleNumber(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int ones=0,twos=0;
            int common_bits=0;
            for(int i=0;i<n;i++)
            {
                twos=twos|(ones&A[i]);
                ones=ones^A[i];
                common_bits=~(twos&ones);
                ones=ones&common_bits;
                twos=twos&common_bits;
            }
            return ones;
        }
};
