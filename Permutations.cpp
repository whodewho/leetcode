/*
   the second is mine, i don't know why it does not work on leetcode, but in eclipse, it's ok
   the first is anson's, good
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


        void dfs(int *p, int n, vector<int>& item, vector<vector<int> >& res,
                vector<int>& num) {
            if (item.size() == n) {
                res.push_back(item);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (!p[i]) {
                    p[i] = 1;
                    item.push_back(num[i]);
                    dfs(p, n, item, res, num);
                    p[i] = 0;
                    item.pop_back();
                }
            }
        }

        vector<vector<int> > permute(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > res;
            int n = num.size();
            if (!n)
                return res;
            int *p = (int *) malloc(sizeof(int) * n);
            memset(p, n, 0);
            vector<int> item;
            dfs(p, n, item, res, num);
            return res;
        }
};
