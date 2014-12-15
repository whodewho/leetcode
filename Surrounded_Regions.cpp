//O(M*N)

class Solution {
    public:

        void solve(vector<vector<char>> &board)
        {
            if(board.empty())return;
            int M=board.size();
            int N=board[0].size();
            for(int i=0;i<M;i++)
            {
                if(board[i][0]=='O')dfs(board,i,0);
                if(board[i][N-1]=='O')dfs(board,i,N-1);
            }
            for(int j=1;j<N-1;j++)
            {
                if(board[0][j]=='O')dfs(board,0,j);
                if(board[M-1][j]=='O')dfs(board,M-1,j);
            }
            for(int i=0;i<M;i++)
                for(int j=0;j<N;j++)
                {
                    if(board[i][j]=='O')board[i][j]='X';
                    else if(board[i][j]=='D')board[i][j]='O';
                }
        }

        void dfs(vector<vector<char>> &board,int i,int j)
        {
            int M=board.size();
            int N=board[0].size();
            board[i][j]='D';

            if(i>0&&board[i-1][j]=='O')dfs(board,i-1,j);
            if(j>0&&board[i][j-1]=='O')dfs(board,i,j-1);
            if(i<M-1&&board[i+1][j]=='O')dfs(board,i+1,j);
            if(j<N-1&&board[i][j+1]=='O')dfs(board,i,j+1);
        }

        void solve(vector<vector<char>> &board)
        {
            if(board.empty())return;
            int M=board.size();
            int N=board[0].size();
            for(int i=0;i<M;i++)
            {
                if(board[i][0]=='O')bfs(board,i,0);
                if(board[i][N-1]=='O')bfs(board,i,N-1);
            }
            for(int j=1;j<N-1;j++)
            {
                if(board[0][j]=='O')bfs(board,0,j);
                if(board[M-1][j]=='O')bfs(board,M-1,j);
            }
            for(int i=0;i<M;i++)
                for(int j=0;j<N;j++)
                {
                    if(board[i][j]=='O')board[i][j]='X';
                    else if(board[i][j]=='D')board[i][j]='O';
                }
        }

        void bfs(vector<vector<char>> &board,int i,int j)
        {
            queue<pair<int,int>> queue;
            board[i][j]='D';
            queue.push(make_pair(i,j));
            int M=board.size();
            int N=board[0].size();
            while(!queue.empty())
            {
                int i=queue.front().first;
                int j=queue.front().second;
                queue.pop();

                if(i>0&&board[i-1][j]=='O')
                {
                    board[i-1][j]='D';
                    queue.push(make_pair(i-1,j));
                }
                if(j>0&&board[i][j-1]=='O')
                {
                    board[i][j-1]='D';
                    queue.push(make_pair(i,j-1));
                }
                if(i<M-1&&board[i+1][j]=='O')
                {
                    board[i+1][j]='D';
                    queue.push(make_pair(i+1,j));
                }
                if(j<N-1&&board[i][j+1]=='O')
                {
                    board[i][j+1]='D';
                    queue.push(make_pair(i,j+1));
                }
            }
        }

};
