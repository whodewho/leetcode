/*
   the second is anson's, i think he prefer one loop.
   */
class Solution {
    public:
        string addBinary(string a, string b) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(a.size()<b.size())
            {
                string tmp=a;
                a=b;
                b=tmp;
            }
            vector<char> res;
            int carry=0;
            int i=a.size()-1,j=b.size()-1;
            while(j>=0)
            {
                res.push_back((a[i]-'0'+b[j]-'0'+carry)%2+'0');
                carry=(a[i]-'0'+b[j]-'0'+carry)/2;
                i--;
                j--;
            }
            while(i>=0)
            {
                res.push_back((a[i]-'0'+carry)%2+'0');
                carry=(a[i]-'0'+carry)/2;
                i--;
            }
            if(carry)
                res.push_back('1');
            reverse(res.begin(),res.end());
            return string(res.begin(),res.end());
        }

        string addBinary(string a, string b) {
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            string::iterator i = a.begin();
            string::iterator j = b.begin();
            string c;
            int carry = 0;
            while (true) {
                int ac, bc;
                if (i != a.end()) ac = *(i++) - '0';
                else ac = 0;
                if (j != b.end()) bc = *(j++) - '0';
                else bc = 0;
                int s = ac + bc + carry;
                c.push_back('0' + (s % 2));
                carry = s / 2;
                if (i == a.end() && j == b.end()) break;
            }
            if (carry == 1) c.push_back('1');
            reverse(c.begin(), c.end());
            return c;
        }
};
