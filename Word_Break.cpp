/*
    O(M^2)
    the first, dp, p[i][j]=true if p[i][k-1]==ture&&p[k][j]==ture,k>=i,k<=j
   */
class Solution {
    public:

        bool wordBreak(string s, unordered_set<string> &dict) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int m=s.size();
            vector<vector<bool> > p(m,(vector<bool>(m,false)));

            for(int l=1;l<=m;l++)
            {
                for(int i=0;i<=m-l;i++)
                {
                    if(dict.find(s.substr(i,l))!=dict.end())
                    {
                        p[i][i+l-1]=true;
                        continue;
                    }
                    for(int k=i+1;k<=i+l-1;k++)
                    {
                        if(p[i][k-1]&&p[k][i+l-1])
                        {
                            p[i][i+l-1]=true;
                            break;
                        }
                    }
                }
            }

            return p[0][m-1];
        }
};
