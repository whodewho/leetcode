/*
    the second solution can only work on small imputs.
    too deep recursion!
    the first solution, yes dynamic planning. trade off between space and time.
formular:table[i+1][j+1]=table[i][j+1]&&s1[i]==s3[i+j+1]||table[i+1][j]&&s2[j]==s3[i+j+1];
    count s3 carefully.
    let me see anson's solution.
    he came up with this two solutions too.
   */
class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            if(s1==""||s2=="")return s3==s1+s2;
            if(s1.size()+s2.size()!=s3.size())return false;

            vector<vector<bool>> table(s1.size()+1,vector<bool>(s2.size()+1,false));
            table[0][0]=s3=="";
            for(int i=0;i<s1.size();i++)
                table[i+1][0]=s1[i]==s3[i];
            for(int j=0;j<s2.size();j++)
                table[0][j+1]=s2[j]==s3[j];

            for(int i=0;i<s1.size();i++)
                for(int j=0;j<s2.size();j++)
                {
                    table[i+1][j+1]=table[i][j+1]&&s1[i]==s3[i+j+1]||table[i+1][j]&&s2[j]==s3[i+j+1];
                }

            return table.back().back();
        }

        bool isInterleave(string s1, string s2, string s3) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            return worker(s1,0,s2,0,s3,0);
        }

        bool worker(string& s1,int i1,string& s2,int i2,string& s3,int i3){
            if(i1==s1.size()&&i2==s2.size()&&i3==s3.size())
                return true;

            bool b1=false,b2=false;
            if(i1<s1.size()&&i3<s3.size()&&s1[i1]==s3[i3])
                b1=worker(s1,i1+1,s2,i2,s3,i3+1);
            if(b1)return true;
            if(i2<s2.size()&&i3<s3.size()&&s2[i2]==s3[i3])
                b2=worker(s1,i1,s2,i2+1,s3,i3+1);
            return b1||b2;
        }
};
