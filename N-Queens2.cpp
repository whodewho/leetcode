/*
    does not make too much sense
    haha, anson is learning
   */
class Solution {
    public:
        int totalNQueens(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int *p = (int *) malloc(sizeof(int) * n);
            int num=0;
            placeQueen(0, n, p, num);
            return num;
        }


        bool check(int row, int col, int *p) {
            for (int i = 0; i < row; i++) {
                if (p[i] == col || abs(row - i) == abs(col - p[i]))
                    return false;
            }
            return true;
        }

        void placeQueen(int row, int n, int *p, int &num) {
            if (row == n) {
                num++;
                return;
            }

            for (int i = 0; i < n; i++) {
                if (check(row, i, p)) {
                    p[row] = i;
                    placeQueen(row + 1, n, p, num);
                }
            }
        }

};
