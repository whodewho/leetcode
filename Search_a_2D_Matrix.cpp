/*
    the second is anson's, his is better.
   */
class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m=matrix.size();
            if(m==0)return false;
            int n=matrix[0].size();
            if(n==0)return false;

            int i=0;
            while(i<m&&matrix[i][n-1]<target)i++;
            if(i==m)return false;
            int j=n-1;
            while(j>=0&&matrix[i][j]>target)j--;
            if(j<0)return false;
            return matrix[i][j]==target;
        }

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

