/*
    O(N*N)
   */
class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = matrix.size();
            if (!n)return;

            for (int i = 0; i < n / 2; i++) {
                int l = n - 2 * i;
                for (int j = i; j < i + l - 1; j++) {
                    int key = matrix[i][j];
                    matrix[i][j] = matrix[n - j - 1][i];
                    matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                    matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                    matrix[j][n - i - 1] = key;
                }
            }

        }
};
