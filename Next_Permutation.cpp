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
                    int j=i,tmp=num[i];
                    while(j<num.size()&&num[j]>num[i-1]&&num[j]<=tmp)
                    {
                        tmp=num[j];
                        j++;
                    }
                    j--;
                    tmp=num[j];
                    num[j]=num[i-1];
                    num[i-1]=tmp;
                    sort(num.begin()+i,num.end());
                    break;
                }
            }
            if(!sign)reverse(num.begin(),num.end());
        }
};
