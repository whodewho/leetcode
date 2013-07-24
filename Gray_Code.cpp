/*
    the second is anson's, his is better.
    A[n]=(n>>1)^n;
    as for solution one, it's fomular is not cool
    0 1
    00 01 11 10
    000 001 011 010 110 111 101 100
    the reverse...
   */
class Solution {
    public:
        vector<int> grayCode(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> res;
            res.push_back(0);
            if(n==0)return res;
            res.push_back(1);
            for(int i=1;i<n;i++)
            {
                vector<int> tmp;
                tmp=res;
                for(int j=res.size()-1;j>=0;j--)
                {
                    tmp.push_back(pow(2,i)+res[j]);
                }
                res=tmp;
            }
            return res;
        }

        vector<int> grayCode(int n) {
            vector<int> result;
            int num = 1 << n;
            for (int i = 0; i < num; i++) {
                result.push_back((i >> 1) ^ i);
            }
            return result;
        }
};
