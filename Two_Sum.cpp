//O(N^2)

//O(N*log(N))

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

        //second try

        struct myclass {
            bool operator()(pair<int, int> comp1, pair<int, int> comp2) {
                return comp1.first < comp2.first;
            }
        } myobject;

        vector<int> twoSum(vector<int> &numbers, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> result;
            vector<pair<int, int> > numbersWithIndex;
            for (size_t i = 0; i != numbers.size(); i++) {
                numbersWithIndex.push_back(make_pair(numbers[i], i + 1));
            }
            std::sort(numbersWithIndex.begin(), numbersWithIndex.end(), myobject);
            size_t i = 0, j = numbers.size() - 1;
            while (i <= j) {
                int tmpSum = numbersWithIndex[i].first + numbersWithIndex[j].first;
                if (tmpSum < target)
                    i++;
                else if (tmpSum > target)
                    j--;
                else {
                    result.push_back(
                            min(numbersWithIndex[i].second,
                                numbersWithIndex[j].second));
                    result.push_back(
                            max(numbersWithIndex[i].second,
                                numbersWithIndex[j].second));
                    break;
                }
            }
            return result;
        }
};
