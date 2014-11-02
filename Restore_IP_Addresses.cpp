/*
  O(pow(4, 3))
 */
class Solution {
    public:
        vector<string> restoreIpAddresses(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> res;
            if(s.size()<4)return res;
            worker(0,3,s,"",res);
            return res;
        }

        void worker(int start,int level,string &s,string prev,vector<string>& res)
        {
            if(level==0)
            {
                string tmp=s.substr(start,s.size()-start);
                if(tmp[0]=='0'&&tmp.size()==1||tmp[0]>'0'&&atoi(tmp.c_str())<256)
                {
                    res.push_back(prev+"."+tmp);
                    return;
                }
            }
            else
            {
                for(int j=start;j<start+3&&j<s.size()-level;j++)
                {
                    string tmp=s.substr(start,j-start+1);
                    if(tmp[0]=='0'&&tmp.size()==1||tmp[0]>'0'&&atoi(tmp.c_str())<256)
                    {
                        if(prev=="")worker(j+1,level-1,s,tmp,res);
                        else worker(j+1,level-1,s,prev+"."+tmp,res);
                    }
                }
            }
        }
};
