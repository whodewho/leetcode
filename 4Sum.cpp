/*
    the first, dfs, for big data, exceed time limit
    the second, anson's, cool, split 4 to 2. 
   */
class Solution {
    public:
        void dfs(vector<int> &num, vector<vector<int> > &result, vector<int> &path,
                int index, int target, int count) {
            if (count == 0) {
                if (target == 0
                        && find(result.begin(), result.end(), path) == result.end()) {
                    result.push_back(path);
                }
                return;
            }
            if (num[index] * count > target) {
                return;
            }

            for (size_t i = index; i != num.size(); i++) {
                path.push_back(num[i]);
                dfs(num, result, path, i + 1, target - num[i], count - 1);
                path.pop_back();
            }

        }

        vector<vector<int> > fourSum(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(num.begin(), num.end());
            vector<vector<int> > result;
            vector<int> path;
            if(!num.empty())dfs(num, result, path, 0, target, 4);
            return result;
        }


        struct TwoSum{
            public:
                TwoSum(int idx1, int idx2, int v) :
                    index1(idx1), index2(idx2), value(v) {}
            public:
                int index1;
                int index2;
                int value;
        };

        struct increaing {
            bool operator() (TwoSum ts1, TwoSum ts2) {
                if (ts1.value == ts2.value){
                    if (ts1.index1 == ts1.index1) return (ts1.index2 < ts2.index2);
                    else return (ts1.index1 < ts2.index1);
                }
                else
                    return (ts1.value < ts2.value);
            }
        };

        class Solution {
            public:
                int find_start_index(vector<TwoSum>& twoSums, int begin, int end, int val){
                    while (begin <= end) {
                        int mid = begin + (end - begin) / 2;
                        if (twoSums[mid].value >= val) end = mid - 1;
                        else begin = mid + 1;
                    }
                    return end + 1;
                };

                int find_end_index(vector<TwoSum>& twoSums, int begin, int end, int val){
                    while (begin <= end) {
                        int mid = begin + (end - begin) / 2;
                        if (twoSums[mid].value <= val) begin = mid + 1;
                        else end = mid - 1;
                    }
                    return begin - 1;
                }

                vector<vector<int> > fourSum(vector<int> &num, int target) {
                    // calculate sum for every two elements and sort
                    vector<TwoSum> twoSums;
                    for (size_t i = 0; i < num.size(); i++){
                        for (size_t j = i + 1; j < num.size(); j++) {
                            twoSums.push_back(TwoSum(i, j, num[i] + num[j]));
                        }
                    }
                    sort(twoSums.begin(), twoSums.end(), increaing());

                    vector<vector<int> > result;
                    for (size_t i = 0; i < twoSums.size(); i++){
                        size_t begin, end;
                        int val = target - twoSums[i].value;

                        begin = find_start_index(twoSums, i + 1, twoSums.size() - 1, val);
                        end = find_end_index(twoSums, i + 1, twoSums.size() - 1, val);

                        for (size_t j = begin; j <= end; j++) {
                            if (twoSums[j].index1 == twoSums[i].index1) continue;
                            if (twoSums[j].index2 == twoSums[i].index1) continue;
                            if (twoSums[j].index1 == twoSums[i].index2) continue;
                            if (twoSums[j].index2 == twoSums[i].index2) continue;

                            vector<int> tmp;
                            tmp.push_back(num[ twoSums[i].index1]);
                            tmp.push_back(num[ twoSums[i].index2]);
                            tmp.push_back(num[ twoSums[j].index1]);
                            tmp.push_back(num[ twoSums[j].index2]);
                            sort(tmp.begin(), tmp.end());

                            if (find(result.begin(), result.end(), tmp) == result.end())
                                result.push_back(tmp);
                        }
                    }
                    return result;
                };
        };
};
