/*
O(N*N)
*/
class Solution {
    public:

        string countAndSay(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            string result = "1";

            for (int i = 1; i < n; i++) {
                int k = 0, count = 0;
                stringstream os;
                for (int j = 0; j < result.size(); j++) {
                    if (result[j] == result[k]) {
                        count++;
                    } else {
                        os << count << result[k];
                        count = 0;
                        k = j;
                        j--;
                    }
                }
                if (count > 0)
                    os << count << result[k];
                result = os.str();
                //cout << result << endl;
            }
            return result;
        }
};
