/*
    where may i use this algo?
   */
class Solution {
    public:
        vector<string> fullJustify(vector<string> &words, int L) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> res;
            for (int i = 0; i < words.size();) {
                int sum1 = words[i].size(), sum2 = sum1;
                int j = i + 1;
                for (; j < words.size() && sum1 + 1 + words[j].size() <= L; j++) {
                    sum1 += (1 + words[j].size());
                    sum2 += words[j].size();
                }
                j--;

                int base = 1, extra = 0;
                if (j > i && j<words.size()-1) {
                    base = (L - sum2) / (j - i);
                    extra = (L - sum2) % (j - i);
                }

                string tmp = words[i];
                for (int k = i + 1; k <= j; k++) {
                    string space(base, ' ');
                    if (extra > 0) {
                        space += " ";
                        extra--;
                    }
                    tmp += space;
                    tmp += words[k];
                }
                if (tmp.size() < L) {
                    string space(L - tmp.size(), ' ');
                    tmp += space;
                }
                res.push_back(tmp);

                i = j + 1;
            }
            return res;
        }
};
