/*
    O(N)
   */
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int carry=1;
            vector<int> res;
            for(int i=digits.size()-1;i>=0;i--)
            {
                res.push_back((digits[i]+carry)%10);
                carry=(digits[i]+carry)/10;  
            }
            if(carry)
                res.push_back(carry);
            reverse(res.begin(),res.end());
            return res;
        }
};
