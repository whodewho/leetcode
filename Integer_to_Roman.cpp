/*
    the second is anson's, cool
   */
class Solution {
    public:
        string intToRoman(int num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            char a[3] = { 'V', 'L', 'D' };
            char b[4] = { 'I', 'X', 'C', 'M' };
            vector<char> strNum;
            while (num) {
                strNum.push_back(num % 10 + '0');
                num = num / 10;
            }
            string result = "";
            for (int i = strNum.size() - 1; i >= 0; i--) {
                if (strNum[i] == '0') {
                    continue;
                } else if (strNum[i] == '5') {
                    result.append(1, a[i]);
                } else if (strNum[i] < '4') {
                    result.append(strNum[i] - '0', b[i]);
                } else if (strNum[i] == '4') {
                    result.append(1, b[i]);
                    result.append(1, a[i]);
                } else if (strNum[i] > '5' && strNum[i] < '9') {
                    result.append(1, a[i]);
                    result.append(strNum[i] - '5', b[i]);
                } else {
                    result.append(1, b[i]);
                    result.append(1, b[i + 1]);
                }
            }
            return result;
        }


        map<int, string> dict;
        string intToRoman(int num) {
            dict.clear();
            dict[1] = "I";
            dict[4] = "IV";
            dict[5] = "V";
            dict[9] = "IX";
            dict[10] = "X";
            dict[40] = "XL";
            dict[50] = "L";
            dict[90] = "XC";
            dict[100] = "C";
            dict[400] = "CD";
            dict[500] = "D";
            dict[900] = "CM";
            dict[1000] = "M";
            string result = "";
            for (map<int, string>::reverse_iterator it = dict.rbegin();
                    it != dict.rend(); it++) {
                while (num >= it->first) {
                    result += it->second;
                    num -= it->first;
                }
            }
            return result;
        }
};
