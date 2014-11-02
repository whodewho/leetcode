/*
O(M*N)
   */
class Solution {
    public:
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
