//well that a trick.two transanctions,  if the the transanctions are seperated by one node
//we need two arrays to store the left and right situation.
//than ,get the max one
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int N = prices.size();
        if (N <= 1) return 0;
        int min_val = prices[0];
        vector<int> left(N, 0);
        for (int i = 1; i < N; ++i)
        {
            if (prices[i] < min_val) min_val = prices[i];
            left[i] = max(left[i-1], prices[i]-min_val);
        }
        int max_val = prices[N-1];
        vector<int> right(N, 0);
        for (int i = N-2; i >= 0; --i)
        {
            if (prices[i] > max_val) max_val = prices[i];
            right[i] = max(right[i+1], max_val-prices[i]);
        }
        int res = 0;
        for (int i = 0; i < N; ++i)
            res = max(res, left[i]+right[i]);
        return res;
    }
};
