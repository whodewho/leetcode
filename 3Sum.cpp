/*
    sort, than dfs will work
    this is anson's, better
   */
class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            int N = num.size();
            sort(num.begin(), num.end());
            vector<vector<int> > result;
            for (int k = 0; k < N-2; k++) {
                int i = k+1;
                int j = N-1;
                while (i < j) {
                    int sum = num[i] + num[j] + num[k];
                    if (sum > 0) j--;
                    else if (sum < 0) i++;
                    else {
                        vector<int> triplet;
                        triplet.push_back(num[i]);
                        triplet.push_back(num[j]);
                        triplet.push_back(num[k]);
                        sort(triplet.begin(), triplet.end());
                        if (find(result.begin(), result.end(), triplet) == result.end()) {
                            result.push_back(triplet);
                        }
                        i++;
                        j--;
                    }
                }
            }
            return result;
        }
};
