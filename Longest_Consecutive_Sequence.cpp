/*
    We can't not sort for the O(n) complexity. so, the trade off between space and time.
    We use hash map. everytime a new integer come to us, we compare it with its neighbor in the hash map. 
    then we update the max length. we always use the max sub length.
 */
class Solution {
    public:
        int longestConsecutive(vector<int> &num) 
        {
            if (num.empty()) return 0;
            unordered_map<int, int> table;
            int res = 1;
            for (size_t i = 0; i < num.size(); i++)
            {
                if (table.find(num[i]) != table.end()) continue;
                table[num[i]] = 1;

                if (table.find(num[i]-1) != table.end())
                {
                    res = max(res, merge(table, num[i]-1, num[i])); 
                }

                if (table.find(num[i]+1) != table.end())
                {
                    res = max(res, merge(table, num[i], num[i]+1));
                }
            }
            return res;
        }

        int merge(unordered_map<int, int> & table, int left, int right)
        {
            int lower = left - table[left] + 1;
            int upper = right + table[right] - 1;
            int len = upper - lower + 1;
            table[lower] = len;
            table[upper] = len;
            return len;
        }
};
