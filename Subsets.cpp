/*
    I said before, the 1<<N is smart, in Subsets2.cpp
    there is no dup, so force.
   */
class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
            // Start typing your C/C++ solution below
            int N = S.size();
            int max = 1 << N;
            vector<vector<int> > res;
            for (int i = 0; i < max; i++) {
                vector<int> sub;
                int k = i;
                int j = 0;
                while (k > 0) {
                    if (k & 0x01) sub.push_back(S[j]);
                    k >>= 1;
                    j++;
                }
                sort(sub.begin(), sub.end());
                res.push_back(sub);
            }
            sort(res.begin(), res.end());
            return res;      
        }
};