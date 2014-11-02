/*
O(N)
 */
class Solution {
    public:
        string simplifyPath(string path) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<string> result;
            for(int i=0;i<path.size();)
            {
                if(path[i]=='/')
                {
                    int j=i+1;
                    while(j<path.size()&&path[j]!='/')j++;
                    if(j==i+1)
                    {
                        i=j;
                        continue;
                    }

                    string tmp=path.substr(i+1,j-i-1);
                    i=j;
                    if(tmp==".")continue;
                    else if(tmp=="..")
                    {
                        if(result.empty())continue;
                        else result.pop_back();
                    }
                    else result.push_back(tmp);
                }
                else
                {
                    i++;
                }
            }

            string str="";
            for(size_t i=0;i<result.size();i++)
                str+=("/"+result[i]);
            if(str=="")
                return "/";
            return str;
        }
};
