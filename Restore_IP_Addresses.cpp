/*
    the second solution, force loop. however, I don't regard this as fool thing.
    the first solution, yes, dfs. I checked, anson use this too. my pleasure.
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

        vector<string> restoreIpAddresses(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<string> res;

            if(s.size()<4)return res;
            for(int i=0;i<s.size()-3;i++)
            {
                string s1=s.substr(0,i+1);
                int i1=atoi(s1.c_str());
                if(s1[0]=='0'&&s1.size()==1||s1[0]>'0'&&i1<=255)
                {
                    for(int j=i+1;j<i+4&&j<s.size()-2;j++)
                    {
                        string s2=s.substr(i+1,j-i);
                        int i2=atoi(s2.c_str());
                        if(s2[0]=='0'&&s2.size()==1||s2[0]>'0'&&i2<=255)
                        {
                            for(int k=j+1;k<j+4&&k<s.size()-1;k++)
                            {
                                string s3=s.substr(j+1,k-j);
                                int i3=atoi(s3.c_str());
                                string s4=s.substr(k+1,s.size()-k-1);
                                int i4=atoi(s4.c_str());
                                if(
                                        (s3[0]=='0'&&s3.size()==1||s3[0]>'0'&&i3<=255)
                                        &&
                                        (s4[0]=='0'&&s4.size()==1||s4[0]>'0'&&i4<=255)
                                  )
                                {
                                    stringstream ss;
                                    ss<<i1<<"."<<i2<<"."<<i3<<"."<<i4;
                                    string tmp=ss.str();
                                    if(find(res.begin(),res.end(),tmp)==res.end())
                                    {
                                        res.push_back(tmp);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            return res;
        }
};
