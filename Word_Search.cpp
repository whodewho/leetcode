/*
    almost same with anson's 
    mine is better, because it passed the first time I submitted,
    and that's mine
   */
class Solution {
    public:
        bool exist(vector<vector<char> > &board, string word) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int M=board.size();
            if(M==0)return false;
            int N=board[0].size();
            if(N==0)return false;
            vector<vector<int>> table(M,vector<int>(N,0));
            for(int i=0;i<M;i++)
                for(int j=0;j<N;j++)
                {
                    if(worker(board,table,M,N,i,j,word,0))
                    {
                        return true;
                    }
                }
            return false;
        }

        bool worker(vector<vector<char> >&board,vector<vector<int>> &table,int M,int N,int i,int j,string &word,int k)
        {
            if(i<0||i>=M||j<0||j>=N)return false;

            if(table[i][j]==0&&board[i][j]==word[k])
            {
                if(k==word.size()-1)return true;
                else
                {
                    table[i][j]=1;
                    if( worker(board,table,M,N,i-1,j,word,k+1) ||
                            worker(board,table,M,N,i,j+1,word,k+1) ||
                            worker(board,table,M,N,i+1,j,word,k+1) ||
                            worker(board,table,M,N,i,j-1,word,k+1))
                    {
                        return true;
                    }
                    table[i][j]=0;
                }
            }
            return false; 
        }
};
