/*
    O(N!)
   */
class Solution {
    public:

        void reverse(vector<int> &num, int i, int j) {
            while (i < j)
                swap(num[i++], num[j--]);
        }

        void nextPermutation(vector<int> &num) {
            int N = num.size();
            if (N < 2)
                return;
            int i = N - 2;
            while (i >= 0 && num[i] >= num[i + 1])
                i--;
            if (i == -1) {
                reverse(num, 0, N - 1);
                return;
            }
            int j = N - 1;
            while (j > i && num[j] <= num[i])
                j--;
            assert(j > i);
            swap(num[i], num[j]);
            reverse(num, i + 1, N - 1);
        }

        vector<vector<int> > permuteUnique(vector<int> &num) {
            vector<vector<int> > result;
            do {
                /*
                   for (int i = 0; i < num.size(); i++)
                   cout << num[i] << " ";
                   cout << endl;
                 */
                result.push_back(num);
                nextPermutation(num);
            } while (!equal(result[0].begin(), result[0].end(), num.begin()));
            return result;
        }
};
