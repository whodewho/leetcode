/*
   nothing special, anson, yours helper is not helpful at all

   the second one, iteration, exceed space limit
 */
class Solution {
    public:

        double pow(double x, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            bool sign=false;
            if(n==0)return 1;
            if(n==1)return x;
            if(n<0){
                n=-n;
                sign=true;   
            }
            double tmp=pow(x,n/2);
            double result;

            if(n%2)result=tmp*tmp*x;
            else result=tmp*tmp;
            if(sign)return 1/result;
            return result;
        }

        double pow(double x, int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(n==0)return 1;
            bool sign=false;
            if(n<0){
                n=-n;
                sign=true;
            }   

            double result=1;
            vector<pair<int,double> > history;
            history.push_back(make_pair(0,1));  
            history.push_back(make_pair(1,x));

            int i=1;
            while(i*2<=n)
            {   
                pair<int,double> tmp=history.back();
                history.push_back(make_pair(2*i,tmp.second*tmp.second));
                i=i*2;          
            }

            while(n>0)
            {
                result=result*(history[(int)(log(n)/log(2))+1].second);
                n=n-history[(int)(log(n)/log(2))+1].first;
            }
            result=result*(history[n].second);

            if(sign)return 1/result;
            else return result;
        } 
};
