/*
   O(n)
 */
class Solution {
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int sum=0,i=0,j=0,k=0,num=0;
            int n=gas.size();
            if(!n)return -1;

            while(num<n)
            {
                sum+=(gas[k]-cost[k]);
                if(sum<0)
                {
                    k=(i-1+n)%n;
                    i=k;
                }
                else
                {
                    k=(j+1)%n;
                    j=k;
                }
                num++;
            }

            if(sum>=0)return i;
            else return -1;
        }
};
