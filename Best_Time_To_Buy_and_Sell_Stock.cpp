lass Solution {
    public:
        int maxProfit(vector<int> &prices) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int res=0;
            int min_i=0;
            for(int i=1;i<prices.size();i++)
            {
                if(prices[i]<prices[min_i])min_i=i;
                int diff=prices[i]-prices[min_i];
                if(diff>res)res=diff;
            }
            return res;
        }
};
