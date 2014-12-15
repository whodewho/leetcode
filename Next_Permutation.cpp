//O(N)

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i=num.size()-1;
            bool sign=false;
            for(;i>0;i--)
            {
                if(num[i]>num[i-1])
                {
                    sign=true;
                    int j=i;
                    //could binary search here, but still O(N)
                    while(j<num.size()&&num[j]>num[i-1])
                    {
                        j++;
                    }
                    j--;
                    swap(num[i-1], num[j]);
                    reverse(num.begin()+i,num.end());
                    break;
                }
            }
            if(!sign)reverse(num.begin(),num.end());
        }
};
