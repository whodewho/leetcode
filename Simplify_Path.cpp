/*
   details in mind, nothing special
   anson used deque, good structure.

   second try
 */
class Solution {
    public:
        string simplifyPath(string path) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<char> str;
            for (int i = 0; i < path.size(); i++) {
                if (path[i] == '/') {
                    if (str.empty()) {
                        str.push_back('/');
                    } else {
                        if (*(str.rbegin()) == '/') {
                            continue;
                        } else {
                            str.push_back('/');
                        }
                    }
                } else if (path[i] == '.') {
                    if (i + 1 < path.size()) {
                        if (path[i + 1] == '.') {
                            str.erase(str.begin() + str.size() - 1);
                            if (str.empty()) {
                                str.push_back('/');
                                continue;
                            } else {
                                while (*(str.rbegin()) != '/')
                                    str.erase(str.begin() + str.size() - 1);
                            }
                        } else if (path[i + 1] != '/') {
                            str.push_back('.');
                        }
                    }
                } else {
                    str.push_back(path[i]);
                }
            }
            if (!str.empty() && *(str.rbegin()) == '/' && str.size() > 1) {
                str.erase(str.begin() + str.size() - 1);
            }

            string res(str.begin(), str.end());
            return res;
        }


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
