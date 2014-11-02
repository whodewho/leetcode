//F(k,x)=F(k+1, x)+F(k, x-x.k) 1<=k<=n, 1<=x<=m, O(N*M*M) 投资问题，不是线性的
//O(1)

class Solution {
    public:
        void worker(int i, int target, vector<int> &count, vector<vector<int> >&result,
                vector<int> &candidates) {
            if (i == candidates.size()) {
                if (target == 0) {
                    vector<int> tmp;
                    for (int i = 0; i < count.size(); i++)
                        for (int j = 0; j < count[i]; j++)
                            tmp.push_back(candidates[i]);
                    result.push_back(tmp);
                }
                return;
            }

            for (int j = 0; j <= target / candidates[i]; j++) {
                count.push_back(j);
                worker(i + 1, target - j * candidates[i], count, result, candidates);
                count.pop_back();
            }

        }
        
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(candidates.begin(),candidates.end());
            vector<vector<int> > result;
            vector<int> count;
            worker(0, target, count, result, candidates);
            return result;
        }
};
