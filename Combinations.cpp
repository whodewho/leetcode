
//O(C(N,K)+C(N,K-1)+C(N,K-2)+C(N,1))=O(pow(N,K)) < O(pow(2,N))
//O(1)

class Solution {
    public:
        vector<vector<int> > combine(int n, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int >> res;
            if(k>n)return res;

            vector<int> item;
            worker(1,n,k,res,item);
            return res;
        }

        void worker(int start,int n,int k,vector<vector<int>> &res,vector<int> &item)
        {
            if(k==0){res.push_back(item);return;}
            if(k>n-start+1)return;

            item.push_back(start);
            worker(start+1,n,k-1,res,item);
            item.pop_back();

            worker(start+1,n,k,res,item);
        }
};
