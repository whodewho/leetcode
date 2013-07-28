/*
    tell me, anson, how dare you use "int y[n]" just like this.
    it's not initialized, no memory malloced for it.
    I used to think the "fill" that works out, no I don't
    and, the stack, good job
    don't worry, the lowest bar will take care of the final result
   */
class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n=height.size();
            int y[n];

            stack<int> stk;
            for (int i = 0; i < n; i++) {
                while (!stk.empty()) {
                    if (height[i] <= height[stk.top()]) stk.pop();
                    else break;
                }
                int j = (stk.empty()) ? -1 : stk.top();
                // Calculating number of bars on the left
                y[i] = i - j - 1;
                stk.push(i);
            }

            while (!stk.empty()) stk.pop();

            for (int i = n - 1; i > 0; i--) {
                while (!stk.empty()) {
                    if (height[i] <= height[stk.top()]) stk.pop();
                    else break;
                }
                int j = (stk.empty()) ? n : stk.top();
                // Calculating number of bars on the left + right
                y[i] += (j - i - 1);
                stk.push(i);
            }

            int res = 0;
            for (int i = 0; i < n; i++) {
                // Calculating height * width
                y[i] = height[i] * (y[i] + 1);
                if (y[i] > res) res = y[i];
            }
            return res;
        }
};
