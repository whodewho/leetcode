i/**
  * Definition for a point.
  * struct Point {
  *     int x;
  *     int y;
  *     Point() : x(0), y(0) {}
  *     Point(int a, int b) : x(a), y(b) {}
  * };
  */

//O(N*N)

class Solution {
	public:
		int gcd(int a, int b){ return a?gcd(b%a, a):b; }

		int maxPoints(vector<Point> &points) {
			int result=0;
			for(int i=0;i<points.size();i++){
				unordered_map<string,int> count;
				int same=1,mx=0;
				for(int j=i+1;j<points.size();j++){
					int x=points[i].x-points[j].x;
					int y=points[i].y-points[j].y;
					int g=gcd(x,y);
					if(!g)
					{
						same++;
						continue;
					}
					x/=g；
					y/=g;
					mx=max(mx,++count[to_string(x)+" "+to_string(y)]);
				}
				result=max(result,mx+same);
			}
			return result;
		}
};
