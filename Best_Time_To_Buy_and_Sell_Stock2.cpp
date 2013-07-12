/*
   beleive or not, the first method is better and clearer.
 */
class Solution {
    public:

        int maxProfit(vector<int> &prices)
        {
            int res = 0;
            for (size_t i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i-1])
                    res += (prices[i] - prices[i-1]);
            return res;
        }

        int maxProfit2(vector<int> &prices) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(prices.empty())return 0;
            int res=0, min_i=0,max_i=0;
            for(int i=1;i<prices.size();i++)
            {
                if(prices[i]>prices[max_i])
                {
                    max_i=i;
                }
                else if(prices[i]<prices[max_i])
                {
                    res+=prices[max_i]-prices[min_i];
                    min_i=max_i=i;
                }
            }
            return res+prices[max_i]-prices[min_i];
        }
};
