/*
   O(max(M,N))
   O(max(M,N))
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
};
