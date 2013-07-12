class Solution {
    public:
        int maxProfit(vector<int> &prices) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(prices.empty())
            {
                return 0;
            }
            int minR,maxR,minT,maxT;
            minR=maxR=minT=maxT=prices[0];
            for(int i=1;i<prices.size();i++)
            {
                if(prices[i]>maxT)
                {
                    maxT=prices[i];
                    if(maxT>maxR)
                    {
                        maxR=maxT;
                    }
                    if(maxT-minT>maxR-minR)
                    {
                        maxR=maxT;
                        minR=minT;
                    }
                }
                if(prices[i]<minT)
                {
                    minT=maxT=prices[i];
                }
            }
            return maxR-minR;
        }
};
