class Solution {
    public:
        int maxArea(vector<int> &height) {
            int i = 0;
            int j = height.size() - 1;
            int max = 0;
            while (i < j) {
                int h = (height[i] < height[j]) ? height[i] : height[j];
                int res = h * (j - i);
                if (res > max) max = res;
                if (height[i] <= height[j]) {
                    i++;
                    while (height[i] < h && i < j) i++;
                }
                else {
                    j--;
                    while (height[j] < h && i < j) j--;
                }
            }
            return max;
        }
};
