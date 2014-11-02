/*
O(2^N)

O(N*N*N)
*/
class Solution {
public:
        vector<string> wordBreak(string s, unordered_set<string> &dict) {
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
                result = getResult(0, m, s, dict);
            return result;
        }

        vector<string> getResult(int i, int m, string &s, unordered_set<string> &dict) {
            vector<string> result;

            for (int k = i; k < m; k++) {
                if (dict.find(s.substr(i, k - i + 1)) != dict.end()) {
                    if (k == m - 1) {
                        result.push_back(s.substr(i, k - i + 1));
                    } else {
                        vector<string> tmp = getResult(k + 1, m, s, dict);
                        for (int t = 0; t < tmp.size(); t++) {
                            result.push_back(s.substr(i, k - i + 1) + " " + tmp[t]);
                        }
                    }
                }
            }

            return result;
        }

        vector<string> wordBreak(string s, unordered_set<string> &dict) {
            int n = s.length();
            // allocate dp array which saves all breaking combinations of sub-string i to the end
            vector<string> res[n+1];
            if(n ==0) return res[0];
            if(dict.size() ==0) return res[0];
            res[n].push_back("");
            // backward pointer matching sub-string from i to j
            for(int i=n-1;i>=0;i--){
                vector<string> newa;
                for(int j=i;j<n;j++){
                    string txt= s.substr(i,j-i+1);
                    vector<string> a(res[j+1]);
                    // complete the string from i to the end by concatenating 
                    // the sub-string of i to j and the sub-strings of j+1 to the end
                    if(dict.find(txt) != dict.end()){
                        for(int k=0;k<a.size();k++){
                            string newtxt= a[k].empty()?txt:txt + " " + a[k];
                            newa.push_back(newtxt);
                        }
                    }
                }
                res[i] = newa;
            }
            return res[0];
        }
};
