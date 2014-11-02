/*
    O(N*N*N)
    O(N*N*N*N)
   */
class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(num.begin(), num.end());
            set<vector<int> > hset;
            vector<vector<int> > result;
        
            for(int i=0;i<num.size();i++)
            {
                for(int j=i+1;j<num.size();j++)
                {
                    for(int k=j+1, l=num.size()-1;k<l;)
                    {
                        int sum=num[i]+num[j]+num[k]+num[l];
                        if(sum>target)
                        {
                            l--;
                        }
                        else if(sum<target)
                        {
                            k++;
                        }
                        else if(sum==target)
                        {
                            vector<int> tmp;
                            tmp.push_back(num[i]);
                            tmp.push_back(num[j]);
                            tmp.push_back(num[k]);
                            tmp.push_back(num[l]);
                            if(hset.find(tmp)==hset.end())
                            {
                                hset.insert(tmp);   
                                result.push_back(tmp);
                            }
        
                            k++;
                            l--;
                        }
                    }
                }
            }
            return result;
        }
};
