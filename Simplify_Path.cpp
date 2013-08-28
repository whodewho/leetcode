/*
   details in mind, nothing special
   anson used deque, good structure.
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
};
