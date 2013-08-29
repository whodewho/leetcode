/*
    anson's code
    ambugrious question, return vector<vector<string> > is more appropiat
    check the res, you will see
   */
class Solution {
    public:
        vector<string> anagrams(vector<string> &strs) {
            map<string, vector<string> > buffer;
            for (int i = 0; i < strs.size(); i++) {
                string copy(strs[i]);
                sort(copy.begin(), copy.end());
                buffer[copy].push_back(strs[i]);
            }
            vector<string> res;
            map<string, vector<string> >::iterator it = buffer.begin();
            while (it != buffer.end()) {
                vector<string> sub = it->second;
                if (sub.size() > 1)
                    for (int i = 0; i < sub.size(); i++)
                        res.push_back(sub[i]);
                it++;
            }
            return res;
        }
};
