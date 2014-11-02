/*
    O(N^(N*N)
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
};
