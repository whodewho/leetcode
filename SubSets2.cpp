/*
O(2^N)
 */
class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
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
                if (find(res.begin(), res.end(), sub) == res.end()) {
                    res.push_back(sub);
                }
            }
            sort(res.begin(), res.end());
            return res;
        }

        void worker(int i,vector<int>& S, vector<int>& path,vector<vector<int> >& result)
        {
            if(i==S.size())
            {
                result.push_back(path);
                return;
            }

            int j=i+1;
            while(j<S.size()&&S[j]==S[i])j++;
            for(int k=0;k<=j-i;k++)
            {
                for(int t=0;t<k;t++)path.push_back(S[i]);
                worker(j,S,path,result);
                for(int t=0;t<k;t++)path.pop_back();
            }
        }

        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<vector<int> > result;
            vector<int> path;
            sort(S.begin(),S.end());

            worker(0,S,path,result);
            return result;
        }
};
