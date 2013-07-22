/*
    yes, dfs
    first, sort! second, count! third, go deep! no duplication!
    will check anson's later
   */
class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(S.begin(),S.end());
            vector<vector<int>> res;
            vector<int> item;
            res.push_back(item);
            for(int i=1;i<=S.size();i++)
                worker(0,i,S,item,res);
            return res;
        }

        void worker(int index,int rest,vector<int>& S,vector<int> &item,vector<vector<int>> &res)
        {
            if(rest!=0&&index>=S.size())return;
            if(rest==0)
            {
                res.push_back(item);
                return;
            }
            int oldIndex=index;

            do
            {
                index++;
            }while(index<S.size()&&S[index]==S[index-1]);


            for(int i=0;i<=index-oldIndex&&i<=rest;i++)
            {
                for(int j=0;j<i;j++)
                    item.push_back(S[oldIndex]);
                worker(index,rest-i,S,item,res);
                for(int j=0;j<i;j++)
                    item.pop_back();
            }
        }
};
