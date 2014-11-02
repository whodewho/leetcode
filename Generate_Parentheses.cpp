/*
O(N*N*N), F(N)=F(N-1)+O(N*N)
*/
class Solution {
    public:

        void worker(int left,int right,int n,string path,vector<string> &result)
        {
            if(right==n)
            {
                result.push_back(path);
                return;
            }

            if(left<n)
            {
                worker(left+1,right,n,path+"(",result);
            }

            if(left>right)
            {
                worker(left,right+1,n,path+")",result);
            }
        }

        vector<string> generateParenthesis(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> result;
            worker(0,0,n,"",result);
            return result;
        }
};
