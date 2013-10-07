/*
    ok, that's it
    how to avoid duplication? from beginning to the end
   */
class Solution {
    public:

        vector<string> getResult(int i, int m, vector<vector<bool> > &p, string &s,
                unordered_set<string> &dict) {
            vector<string> result;

            for (int k = i; k < m; k++) {
                if (p[i][k] && dict.find(s.substr(i, k - i + 1)) != dict.end()) {
                    if (k == m - 1) {
                        result.push_back(s.substr(i, k - i + 1));
                    } else {
                        vector<string> tmp = getResult(k + 1, m, p, s, dict);
                        for (int t = 0; t < tmp.size(); t++) {
                            result.push_back(s.substr(i, k - i + 1) + " " + tmp[t]);
                        }
                    }
                }
            }

            return result;
        }

        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int m = s.size();
            vector<vector<bool> > p(m, (vector<bool>(m, false)));
            //vector<vector<vector<int> > > dividors(m, (vector<vector<int> >(m, vector<int>())));

            for (int l = 1; l <= m; l++) {
                for (int i = 0; i <= m - l; i++) {
                    if (dict.find(s.substr(i, l)) != dict.end()) {
                        p[i][i + l - 1] = true;
                        //dividors[i][i + l - 1].push_back(i);
                    }

                    for (int k = i + 1; k <= i + l - 1; k++) {
                        if (p[i][k - 1] && p[k][i + l - 1]) {
                            p[i][i + l - 1] = true;
                            //dividors[i][i + l - 1].push_back(k);
                        }
                    }
                }
            }

            vector<string> result;
            if (p[0][m - 1])
                result = getResult(0, m, p, s, dict);
            return result;
        }

};
