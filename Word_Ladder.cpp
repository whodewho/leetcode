/*
    use queue, no doubt. how to get the nest start faster? the word is short, and we use set. Iterate through the word will be faster
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
/*
        int ladderLength1(string start, string end, unordered_set<string> &dict) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            queue<pair<string,int>> queue;
            queue.push(make_pair(start,1));
            int res=0;
            bool sign=false;
            while(!queue.empty()&&!sign)
            {   
                pair<string,int> item=queue.front();
                queue.pop();
                dict.erase(item.first);
                set<string> starts=next(item.first,end,dict);
                for(set<string>::iterator it=starts.begin();it!=starts.end()&&!sign;it++)
                {
                    if(*it==end)
                    {
                        res=item.second+1;
                        sign=true;
                        break;
                    }
                    queue.push(make_pair(*it,item.second+1));
                    dict.erase(*it);
                }
            }
            return res;
        }

        int ladderLength2(string start,string end,unordered_set<string>& dict){

            unordered_set<string> arg;
            for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++)
            {
                arg.insert(*it);
            }
            return worker(start,end,arg);
        }
        int worker(string start,string end,unordered_set<string> dict){
            dict.erase(start);
            set<string> newStarts=next(start,end,dict);
            if(newStarts.find(end)!=newStarts.end())
                return 2;

            int sub=dict.size()+3;

            for(set<string>::iterator it=newStarts.begin();it!=newStarts.end();it++)
            {
                dict.erase(*it);
            }
            for(set<string>::iterator it=newStarts.begin();it!=newStarts.end();it++)
            {
                int tmp=ladderLength(*it,end,dict);
                if(tmp==0)continue;
                else if(tmp<sub)
                {
                    sub=tmp;
                }
            }

            if(sub==dict.size()+3)
                return 0;
            else
                return 1+sub;
        }

        set<string> next2(string start,string end,unordered_set<string> &dict){
            int dis=start.length()+1;
            set<string> newStarts;
            if(distance(start,end)==1)
            {
                newStarts.insert(end);
                return newStarts;
            }
            for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++)
            {
                if(distance(start,*it)==1)
                {
                    newStarts.insert(*it);
                    //dict.erase(*it);
                }
            }
            return newStarts;
        }

        int distance(string first,string second)
        {
            int dis=0;
            for(int i=0;i<first.size();i++)
            {
                if(first[i]!=second[i])dis++;
                if(dis>1)return 2;
            }
            return dis;
        }
*/
};
