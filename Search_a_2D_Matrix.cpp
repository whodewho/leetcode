/*
O(M+N)
   */
class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int M = matrix.size();
            if (M == 0) return false;
            int N = matrix[0].size();
            if (N == 0) return false;
            if (target < matrix[0][0] || target > matrix[M-1][N-1]) return false;
            int i = 0, j = N - 1;
            while (i < M && j >= 0) {
                if (matrix[i][j] < target) i++;
                else if (matrix[i][j] > target) j--;
                else return true;
            }
            return false;
        }
};

