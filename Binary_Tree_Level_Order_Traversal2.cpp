/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//O(N)
//O(N)

class Solution {
    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > res;
            vector<int> row;
            queue<TreeNode*> currQ;
            int currNum = 1, nextNum = 0;
            if (root) currQ.push(root);
            while (!currQ.empty()) {
                TreeNode* front = currQ.front();
                currQ.pop(), currNum--;
                row.push_back(front->val);
                if (front->left) currQ.push(front->left), nextNum++;
                if (front->right) currQ.push(front->right), nextNum++;
                if (currNum == 0) {
                    res.push_back(row);
                    row.clear();
                    currNum = nextNum;
                    nextNum = 0;
                }
            }
            reverse(res.begin(),res.end());
            return res;
        }

        vector<vector<int> > levelOrderBottom2(TreeNode *root)
        {
            vector<vector<int> > res;
            if (!root) return res;

            stack<vector<TreeNode*> > stk;
            stk.push(vector<TreeNode*>(1, root));
            while(true)
            {
                vector<TreeNode*> row;
                for (vector<TreeNode*>::iterator it = stk.top().begin(); it != stk.top().end(); ++it)
                {
                    if ((*it)->left) row.push_back((*it)->left);
                    if ((*it)->right) row.push_back((*it)->right);
                }
                if (row.empty()) break;
                stk.push(row);
            }

            while (!stk.empty())
            {
                vector<int> row;
                for (vector<TreeNode*>::iterator it = stk.top().begin(); it != stk.top().end(); ++it)
                    row.push_back((*it)->val);
                res.push_back(row);
                stk.pop();
            }
            return res;
        }
};
