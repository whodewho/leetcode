/*
   the second is anson's, mine is better, always start from the minimum point
 */
class Solution {
    public:

        char chars[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

        bool worker(int depth, vector<vector<char> > &board, vector<set<char> > &row,
                vector<set<char> > &col, vector<set<char> > &cross) {
            if (depth == 0)
                return true;
            int startI = -1, startJ = -1;
            set<char> startSet;
            for (size_t i = 0; i < 9; i++) {
                for (size_t j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        set<char> init(chars, chars + 9);
                        for (char k = '1'; k <= '9'; k++) {
                            if (row[i].find(k) == row[i].end()
                                    || col[j].find(k) == col[j].end()
                                    || cross[i / 3 * 3 + j / 3].find(k)
                                    == cross[i / 3 * 3 + j / 3].end()) {
                                init.erase(k);
                            }
                        }
                        if (init.empty())
                            return false;
                        if (startI == -1 || init.size() < startSet.size()) {
                            startI = i;
                            startJ = j;
                            startSet = init;
                        }
                    }
                }
            }

            for (set<char>::iterator it = startSet.begin(); it != startSet.end();
                    it++) {
                row[startI].erase(*it);
                col[startJ].erase(*it);
                cross[startI / 3 * 3 + startJ / 3].erase(*it);
                board[startI][startJ] = *it;
                if (worker(depth - 1, board, row, col, cross)) {
                    return true;
                }
                row[startI].insert(*it);
                col[startJ].insert(*it);
                cross[startI / 3 * 3 + startJ / 3].insert(*it);
                board[startI][startJ] = '.';
            }
            return false;
        }

        void solveSudoku(vector<vector<char> > &board) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            set<char> init(chars, chars + 9);
            vector<set<char> > row(9, init);
            vector<set<char> > col(9, init);
            vector<set<char> > cross(9, init);

            int depth = 0;
            for (size_t i = 0; i < 9; i++)
                for (size_t j = 0; j < 9; j++) {
                    if (board[i][j] == '.') {
                        depth++;
                        continue;
                    }

                    row[i].erase(board[i][j]);
                    col[j].erase(board[i][j]);
                    cross[i / 3 * 3 + j / 3].erase(board[i][j]);
                }

            worker(depth, board, row, col, cross);
        }





        void solveSudoku(vector<vector<char> > &board) {
            solve(board, 0, 0);
        }

        bool solve(vector<vector<char> > &board, int row, int col) {
            bool res = getNextEmpty(board, row, col);
            if (!res) return true;
            vector<char> possible;
            getPossibleValues(board, possible, row, col);
            if (possible.size() == 0) return false;
            for (size_t i = 0; i < possible.size(); i++) {
                board[row][col] = possible[i];
                if (solve(board, row, col)) return true;
                board[row][col] = '.';
            }
            return false;
        }

        bool getNextEmpty(vector<vector<char> > &board, int &row, int &col) {
            while (row <= 8 && col <= 8) {
                if (board[row][col] == '.') return true;
                row = (col == 8) ? row + 1 : row;
                col = (col == 8) ? 0 : col + 1;
            }
            return false;
        }

        void getPossibleValues(vector<vector<char> > &board, vector<char> &possible, int row, int col) {
            bool s[9] = { false };
            for (int i = 0; i < 9; i++) {
                if (board[row][i] != '.') s[board[row][i]-'1'] = true;
                if (board[i][col] != '.') s[board[i][col]-'1'] = true;
                char c = board[row/3*3+i/3][col/3*3+i%3];
                if (c!='.') s[c-'1'] = true;
            }
            for (int i = 0; i < 9; i++) {
                if (!s[i]) possible.push_back('1'+i);
            }
        }
};
