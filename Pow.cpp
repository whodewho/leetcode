/*
   O(log(N))

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
};
