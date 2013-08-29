/*
    checked anson's, mine is cool
   */
class Solution {
    public:
        bool check(int row, int col, int *p) {
            for (int i = 0; i < row; i++) {
                if (p[i] == col || abs(row - i) == abs(col - p[i]))
                    return false;
            }
            return true;
        }

        void placeQueen(int row, int n, int *p, vector<vector<string> > &res) {
            if (row == n) {
                vector<string> tmp(n, string(n, '.'));
                for (int i = 0; i < n; i++) {
                    tmp[i][p[i]] = 'Q';
                }
                res.push_back(tmp);
                return;
            }

            for (int i = 0; i < n; i++) {
                if (check(row, i, p)) {
                    p[row] = i;
                    placeQueen(row + 1, n, p, res);
                }
            }
        }

        vector<vector<string> > solveNQueens(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<string> > res;
            int *p = (int *) malloc(sizeof(int) * n);
            placeQueen(0, n, p, res);
            return res;
        }
};
