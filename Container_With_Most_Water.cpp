/*
O(N)
*/
class Solution {
	public:
		int maxArea(vector<int> &height) {
			int i=0,j=height.size()-1;
			int result=min(height[i],height[j])*(j-i);
			while(i<j)
			{
				int h = min(height[i],height[j]);
				if(height[i]<height[j])
				{
					while(height[i]<=h)i++;
				}
				else
				{
					while(j>i&&height[j]<=h)j--;
				}
				result=max(min(height[i], height[j]) * (j-i), result);
			}
			return result;
		}
};
