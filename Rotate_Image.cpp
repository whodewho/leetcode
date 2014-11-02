/*
    O(N*N)
   */
class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m = matrix.size();
            if (!m)
                return;
            int n = matrix[0].size();
            if (!n)
                return;

            for (int i = 0; i < m / 2; i++) {
                int l = n - 2 * i;
                for (int j = i; j < i + l - 1; j++) {
                    int key = matrix[i][j];
                    matrix[i][j] = matrix[m - j - 1][i];
                    matrix[m - j - 1][i] = matrix[m - i - 1][n - j - 1];
                    matrix[m - i - 1][n - j - 1] = matrix[j][n - i - 1];
                    matrix[j][n - i - 1] = key;
                }
            }

        }
};
