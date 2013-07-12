class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        paths.clear();
        dict.insert(start);
        dict.insert(end);
        unordered_map<string,vector<string>> traces;
        vector<string> prev;
        for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++)
        {
            traces[*it]=prev;
        }
        int pre=0,cur=1;
        vector<unordered_set<string>> layers(2);
        layers[cur].insert(start);
        
        while(true)
        {
            cur=!cur;
            pre=!pre;
            
            for(unordered_set<string>::iterator it=layers[pre].begin();it!=layers[pre].end();it++)
            {
                dict.erase(*it);
            }
            layers[cur].clear();
            
            for(unordered_set<string>::iterator it=layers[pre].begin();it!=layers[pre].end();it++)
            {
                for (size_t i = 0; i < (*it).size(); i++)
                {
                    string copy(*it);
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        copy[i] = c;
                        if (dict.find(copy) != dict.end())
                        {
                            layers[cur].insert(copy);
                            traces[copy].push_back(*it);
                        }
                    }
                }
            }
            if(layers[cur].size()==0)
                return paths;
            if(layers[cur].count(end))
                break;
        }
        vector<string> path;
        buildPath(traces,path,end);
        return paths;
    }
    
    private:
        void buildPath(unordered_map<string,vector<string>>& traces,vector<string>& path,string end)
        {
            if(traces[end].size()==0)
            {
                path.push_back(end);
                vector<string> tmpVec=path;
                reverse(tmpVec.begin(),tmpVec.end());
                paths.push_back(tmpVec);
                path.pop_back();
                return;
            }
            
            path.push_back(end);
            for(vector<string>::iterator it=traces[end].begin();it!=traces[end].end();it++)
            {
                buildPath(traces,path,*it);
            }
            path.pop_back();
        }
    
        vector<vector<string>> paths;
};
