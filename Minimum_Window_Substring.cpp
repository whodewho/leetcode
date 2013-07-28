/*
    checked anson's ,mine is better
    needtofind->in
    hasfound->counts

   */
class Solution {
    public:
        string minWindow(string S, string T) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int M=S.size(),N=T.size();
            string res="";
            queue<int> queue;
            if(M<N)return res;

            int counts[128],sum=N,min=M+1;
            fill(counts,counts+128,0);
            bool in[128];
            fill(in,in+128,false);

            for(int i=0;i<N;i++)
            {
                counts[T[i]]++;   
                in[T[i]]=true;
            }

            for(int i=0;i<M;i++)
            {
                if(in[S[i]])
                {
                    queue.push(i);
                    counts[S[i]]--;
                    if(counts[S[i]]>=0)sum--;
                    if(sum==0)
                    {
                        int start=queue.front();
                        int end=queue.back();
                        while(counts[S[start]]<0)
                        {
                            counts[S[start]]++;
                            queue.pop();
                            start=queue.front();
                        }

                        if(end-start+1<min)
                        {
                            min=end-start+1;
                            res=S.substr(start,end-start+1);
                        }

                        counts[S[start]]++;
                        queue.pop();
                        sum++;
                    }
                }
            }
            return res;
        }
};
