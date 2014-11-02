/*
O(2^N)
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

        vector<vector<int> > subsets(vector<int> &S) {
            vector<vector<int>> re;     
            sort(S.begin(),S.end());
            re.push_back(vector<int>());
            for(int i=0;i<S.size();++i)
            {
                int size=re.size();
                for(int j=0;j<size;++j)
                {
                    //vector<int> tmp=re[j];
                    //tmp.push_back(S[i]);
                    re.push_back(re[j]);
                    re[re.size()-1].push_back(S[i]);
                }
            }
            return re;
        }
};
