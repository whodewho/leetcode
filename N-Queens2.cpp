/*
   second try, iterative way, that's interesting, exceed time limit
 */
class Solution {
    public:
        int totalNQueens(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int *p = new int[n];
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

        int totalNQueens(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int count=0;
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
                        count++; //k=N-1 表示也可构成一个排法；
                    }
                    else {
                        k++;
                    }
                } else {
                    x[k] = -1; //when go back, recover the enviroment
                    k--;
                }
            }
            return count;
        }
};
