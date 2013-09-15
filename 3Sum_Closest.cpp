class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int N = num.size();
            sort(num.begin(), num.end());
            int result=num[0]+num[1]+num[2];
            for (int k = 0; k < N-2; k++) {
                int i = k+1;
                int j = N-1;
                while (i < j) {
                    int sum = num[i] + num[j] + num[k];
                    if(abs(sum-target)<abs(result-target))
                    {
                        result=sum;
                    }

                    if (sum-target > 0) j--;
                    else if (sum-target < 0) i++;
                    else {
                        return result;
                    }
                }
            }
            return result;
        }
};
