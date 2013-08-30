class Solution {
    public:

        void worker(int i, int target, vector<int> &count, vector<vector<int> >&result,
                vector<int> &candidates, map<int, int>&number) {
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

            for (int j = 0; j <= target / candidates[i] && j <= number[candidates[i]];
                    j++) {
                count.push_back(j);
                worker(i + 1, target - j * candidates[i], count, result, candidates,
                        number);
                count.pop_back();
            }

        }
        vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(candidates.begin(), candidates.end());
            map<int, int> number;
            vector<int> newCandidates;
            for (int i = 0; i < candidates.size(); i++) {
                if (number.find(candidates[i]) == number.end()) {
                    newCandidates.push_back(candidates[i]);
                    number.insert(pair<int, int>(candidates[i], 1));
                } else {
                    number[candidates[i]] = number[candidates[i]] + 1;
                }
            }

            vector<vector<int> > result;
            vector<int> count;
            worker(0, target, count, result, newCandidates, number);
            return result;
        }
};
