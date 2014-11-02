/*
O(N*K)
*/
class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            queue<pair<string,int>> queue;
            queue.push(make_pair(start,1));

            while(!queue.empty())
            {   
                pair<string,int> item=queue.front();
                queue.pop();

                if(item.first==end)
                {
                    return item.second;
                }

                set<string> starts=next(item.first,dict);
                for(set<string>::iterator it=starts.begin();it!=starts.end();it++)
                {
                    queue.push(make_pair(*it,item.second+1));
                }
            }
            return 0;
        }

        set<string> next(string start,unordered_set<string> &dict){
            set<string> res;
            for (size_t i = 0; i < start.size(); i++)
            {
                string copy(start);
                for (char c = 'a'; c <= 'z'; c++)
                {
                    copy[i] = c;
                    if (dict.find(copy) != dict.end())
                    {
                        res.insert(copy);
                        dict.erase(copy);
                    }
                }
            }
            return res;
        }
};
