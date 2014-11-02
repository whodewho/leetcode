//O(N)
//O(1)

class Solution {
public:
    int candy(vector<int> &ratings) {
        int sum=0, n=ratings.size();
        if(!n)return sum;
        
        vector<int> count(n, 1);
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                count[i]=count[i-1]+1;
            }
        }
        
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                count[i]=max(count[i], count[i+1]+1);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            sum+=count[i];
        }
        return sum;
    }
};
