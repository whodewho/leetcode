class Solution {
public:

    bool isPalindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        vector<vector<string>> result;
        for(int i=1;i<=s.size();i++)
        {
            string head=s.substr(0,i);
            if(isPalindrome(head))
            {
                if(i==s.size())
                {
                    vector<string> tmp;
                    tmp.push_back(head);
                    result.push_back(tmp);
                    return result;
                }
                string tail=s.substr(i,s.size()-i);
                vector<vector<string>> sub=partition(tail);

                for(int j=0;j<sub.size();j++)
                {
                    sub[j].insert(sub[j].begin(),head);
                    result.push_back(sub[j]);
                }
            }
        }
        return result;
    }
};
