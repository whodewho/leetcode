/*
O(N!)
 */
class Solution {
    public:

        void permuteHelper(vector<int> num, int i, vector<vector<int> > &result) {
            if (i == num.size()) result.push_back(num);
            else {
                for (int j = i; j < num.size(); j++) {
                    //if(i!=j&&num[i]==num[j])continue;
                    swap(num[i], num[j]);
                    permuteHelper(num, i + 1, result);
                    swap(num[i], num[j]);
                }
            }
        }

        vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> > result;
            permuteHelper(num, 0, result);
            return result;
        }
};
