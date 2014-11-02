/*
    O(pow(8, 8))
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

        // second try, iterative way
        int place(int k,vector<int>& x) //判断是否符合要求；
        {
            int j;
            for (j = 0; j < k; j++) {
                if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
                    return 0;
            }
            return 1;
        }

        vector<vector<string> > solveNQueens(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<string> > result;
            vector<int> x(n,-1);

            int i, k;
            x[0] = -1;
            k = 0;
            while (k >= 0) {
                x[k] += 1;
                while ((x[k] < n) && !(place(k,x)))
                    x[k] += 1;
                if (x[k] < n) {
                    if (k == n- 1)
                    {
                        // count++; //k=N-1 表示也可构成一个排法；
                        vector<string> tmp(n,string(n,'.'));
                        for(int j=0;j<n;j++)
                            tmp[j][x[j]]='Q';
                        result.push_back(tmp);
                    }
                    else {
                        k++;
                    }
                } else {
                    x[k] = -1; //when go back, recover the enviroment
                    k--;
                }
            }

            return result;
        }
};
