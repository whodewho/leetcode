/*
   almost same with anson's 
   mine is better, because it passed the first time I submitted,
   and that's mine

   second try, as better 
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


        bool worker(int i,int j,int m,int n,string word,vector<vector<bool> >& p,vector<vector<char> >&board)
        {
            if(word.empty())return true;

            if(p[i][j]==false&&board[i][j]==word[0])
            {
                if(word.size()==1)return true;

                p[i][j]=true;
                word.erase(word.begin());
                if(i+1<m && worker(i+1,j,m,n,word,p,board)) return true;
                if(i-1>=0 && worker(i-1,j,m,n,word,p,board)) return true;
                if(j+1<n && worker(i,j+1,m,n,word,p,board)) return true;
                if(j-1>=0 && worker(i,j-1,m,n,word,p,board)) return true;
                p[i][j]=false;
            }
            return false;
        }

        bool exist(vector<vector<char> > &board, string word) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int m=board.size();
            if(!m)return false;
            int n=board[0].size();
            if(!n)return false;

            vector<vector<bool> > p(m,vector<bool>(n,false));
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                {
                    if(worker(i,j,m,n,word,p,board))
                        return true;
                }
            return false;
        }
};
