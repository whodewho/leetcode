//O(N)
class Solution {
public:
    void reverseWords(string &s) {
        int i=0;
        while(s.size()>0&&isspace(s[0]))s.erase(0,1);
        while(s.size()>0&&isspace(s[s.size()-1]))s.erase(s.size()-1, 1);
        if(s.size()==1)return;
        reverse(s.begin(),s.end());
        
        i=0;
        for(;i<s.size();i++)
        {
            if(isspace(s[i]))
            {
                int j=i+1;
                while(j<s.size()&&isspace(s[j]))
                {
                    s.erase(j, 1);
                }
            }
            else
            {
                int j=i;
                while(j<s.size()&&!isspace(s[j]))j++;
                reverse(s.begin()+i, s.begin()+j);
                i=j-1;
            }
        }
    }
};