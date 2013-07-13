/*
    dfs will work. but not efficient. we can build the path from the bottom, yes the opposite direction.
    we need space to record the shortest path from the node to bottom.
    if we can use triangle as the container, we need no other space, but, it will destroy the argument.if you don't mind.
   */
class Solution {
    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int >> table;
            table.push_back(triangle.back());
            int N=triangle.size();
            for(int i=N-2;i>=0;i--)
            {
                vector<int> item;
                for(int j=0;j<=i;j++)
                {
                    item.push_back(triangle[i][j]+min(table[N-i-2][j],table[N-i-2][j+1]));
                }
                table.push_back(item);
            }
            return table.back().back();
        }
        /*
        int minimumTotal(vector<vector<int> > &triangle) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            return worker(triangle,0,0);
        }
        int worker(vector<vector<int> > &triangle,int i,int j){
            if(i==triangle.size()-1)return triangle[i][j];
            int tmpV=min(worker(triangle,i+1,j),worker(triangle,i+1,j+1));
            return tmpV+triangle[i][j];
        }
        */
};
