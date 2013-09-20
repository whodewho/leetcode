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

        //iterative way
        #define N 10 
        int x[N] = { 0 };

        int place(int k) //判断是否符合要求；
        {
            int j;
            for (j = 0; j < k; j++) {
                if ((abs(k - j) == abs(x[j] - x[k])) || (x[j] == x[k]))
                    return 0;
            }
            return 1;
        }
        void queen(int &count) {
            int i, k;
            x[0] = -1;
            k = 0;
            while (k >= 0) {
                x[k] += 1;
                while ((x[k] < N) && !(place(k)))
                    x[k] += 1;
                if (x[k] < N) {
                    if (k == N - 1)
                        count++; //k=N-1 表示也可构成一个排法；
                    else {
                        k++;
                    }
                } else {
                    x[k] = -1; //when go back, recover the enviroment
                    k--;
                }
            }
        }
};
