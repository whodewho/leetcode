/*
    the second is anson's, mine exceed the time limites.
    compare the two, two map, one map and a copy, that's the difference

    as for the S.size()-m*n, be careful about the significant bit
    static_cast is necessary
   */
class Solution {
    public:
        vector<int> findSubstring(string S, vector<string> &L) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> result;
            int m = L.size();
            int n = L[0].size();

            map<string, int> counts;
            for (int j = 0; j < m; j++) {
                counts[L[j]]++;
            }

            for (size_t i = 0; i < S.size() - m * n+1; i++) {
                map<string, int> tmpCounts = counts;
                int k = 0;
                for (; k < m; k++) {
                    string tmpStr = S.substr(i + k * n, n);
                    vector<string>::iterator itExist = find(L.begin(), L.end(), tmpStr);
                    if (itExist == L.end()) {
                        break;
                    } else {
                        if (tmpCounts[tmpStr] > 0) {
                            tmpCounts[tmpStr]--;
                        } else {
                            break;
                        }
                    }
                }

                if (k == m) {
                    result.push_back(i);
                }
            }
            return result;
        }


        vector<int> findSubstring(string S, vector<string> &L) {
            map<string, int> toFind;
            map<string, int> hasFound;
            for (size_t i = 0; i < L.size(); i++) toFind[L[i]]++;
            int N = L.size();
            int M = L[0].size();
            vector<int> res;
            for (int i = 0; i <= (int)S.size() - N * M; i++) {
                hasFound.clear();
                int j;
                for (j = 0; j < N; j++) {
                    int k = i + j * M;
                    string sub = S.substr(k, M);
                    if (toFind.find(sub) == toFind.end()) break;
                    hasFound[sub]++;
                    if (hasFound[sub] > toFind[sub]) break;
                }
                if (j == N) res.push_back(i);
            }
            return res;
        }
};
