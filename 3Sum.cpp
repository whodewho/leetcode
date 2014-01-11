/*
   sort, than dfs will work
   this is anson's, better

   the input become harder, revise one
   */


class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> &num) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			vector<vector<int> > result;
			int m=num.size();
			if(!m)return result;

			sort(num.begin(),num.end());
			vector<int> last;
			for(int i=0;i<m-2;i++)
			{
				if (i>0 && num[i]==num[i-1]) continue; 
				int j=i+1,k=m-1;
				while(j<k)
				{
					int tmpSum=num[i]+num[j]+num[k];
					if(tmpSum>0)k--;
					else if(tmpSum<0)j++;
					else{
						vector<int> tmpVec;
						tmpVec.push_back(num[i]);
						tmpVec.push_back(num[j]);
						tmpVec.push_back(num[k]);

						result.push_back(tmpVec);

						do{j++;}while(k>j&&num[j]==num[j-1]);
						do{k--;}while(k>j&&num[k]==num[k+1]);
					}
				}
			}
			return result;
		}
};
