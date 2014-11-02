/*
O(M*N)
   */
class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            if(s1==""||s2=="")return s3==s1+s2;
            int m=s1.size(), n=s2.size(), k=s3.size();
            if(m+n!=k)return false;

            vector<vector<bool>> table(m+1,vector<bool>(n+1,false));
            table[0][0]=true;
            for(int i=0;i<m;i++)
                table[i+1][0]=s1[i]==s3[i]&&table[i][0];
            for(int j=0;j<n;j++)
                table[0][j+1]=s2[j]==s3[j]&&table[0][j];

            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                {
                    table[i+1][j+1]=table[i][j+1]&&s1[i]==s3[i+j+1]||table[i+1][j]&&s2[j]==s3[i+j+1];
                }

            return table.back().back();
        }
};
