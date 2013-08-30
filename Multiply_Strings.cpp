/*
    the second is anson's, his is better
     as for add, just add
   */
class Solution {
    public:
        string multiply(string num1, string num2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> res;
            for (int i = num2.size() - 1; i >= 0; i--) {
                vector<int> tmp;
                int carry = 0;
                for (int j = num1.size() - 1; j >= 0; j--) {
                    tmp.push_back(((num2[i] - '0') * (num1[j] - '0') + carry) % 10);
                    carry = ((num2[i] - '0') * (num1[j] - '0') + carry) / 10;
                }
                if (carry != 0)
                    tmp.push_back(carry);

                carry = 0;
                int base = num2.size() - 1 - i;

                for (int j = 0; j < tmp.size(); j++) {
                    if (base + j < res.size()) {
                        int t = res[base + j];
                        res[base + j] = (t + tmp[j] + carry) % 10;
                        carry = (t + tmp[j] + carry) / 10;

                    } else {
                        res.push_back((tmp[j] + carry) % 10);
                        carry = (tmp[j] + carry) / 10;

                    }
                }
                if (carry != 0)
                    res.push_back(carry);
            }

            int i = res.size() - 1;
            while (i >= 0 && res[i] == 0)
                i--;
            if (i == -1)
                return "0";
            else {
                stringstream os;
                for (; i >= 0; i--)
                    os << res[i];
                return os.str();
            }
        }

        string multiply(string num1, string num2) {
            int n1 = num1.size(), n2 = num2.size();
            int n3 = n1+n2;
            int num3[n3];
            memset(num3, 0, sizeof(int)*(n3));
            for (int i = n1 - 1; i >= 0; i--) {
                int carry = 0, j, t;
                for (j = n2 - 1; j >= 0; j--) {
                    t = carry + num3[i+j+1] + (num1[i]-'0') * (num2[j]-'0');
                    num3[i+j+1] = t % 10;
                    carry = t / 10;
                }
                num3[i+j+1] = carry;
            }
            string res = "";
            int i = 0;
            while (i < n3-1 && num3[i] == 0) i++;
            while (i < n3) res.push_back('0' + num3[i++]);
            return res;
        }
};
