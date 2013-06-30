class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> result;
            vector<int> copy(numbers.begin(),numbers.end());
            sort(copy.begin(),copy.end());
            int i=0,j=copy.size()-1;
            while(i<j)
            {
                int sum=copy[i]+copy[j];
                if(sum<target)
                    i++;
                else if(sum>target)
                    j--;
                else
                {
                    for(int k=0;k<numbers.size();k++)
                    {
                        if(numbers[k]==copy[i]||numbers[k]==copy[j])
                        {
                            result.push_back(k+1);
                        }
                    }
                    break;
                }
            }
            sort(result.begin(),result.end());
            return result;
        }

        vector<int> twoSum2(vector<int> &numbers, int target) {
            map<int, int> hash;
            vector<int> result;

            for (int i = 0; i < numbers.size(); i++) {
                if (hash.find(target - numbers[i]) != hash.end()) {
                    if (i + 1 < hash[target - numbers[i]]) {
                        result.push_back(i + 1);
                        result.push_back(hash[target - numbers[i]]);
                    } else {
                        result.push_back(hash[target - numbers[i]]);
                        result.push_back(i + 1);
                    }
                    break;
                } else {
                    hash[numbers[i]] = i + 1;
                }
            }
            return result;
        }
};
