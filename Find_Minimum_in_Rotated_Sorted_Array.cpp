/*
O(log(N))
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        if(num.empty())return -1;
        int l=0, h=num.size()-1;
        while(l<=h)
        {
            if(num[l]<num[h])return num[l];
            int m=(l+h)/2;
            if(l==m)return min(num[l], num[h]);
         
            if(num[m]>num[l])l=m;
            else h=m;
        }
    }
};