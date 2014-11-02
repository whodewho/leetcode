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
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> result;
            if(!root)return result;
            stack<TreeNode*> stk;
            while(!stk.empty()||root)
            {
                if(root)
                {
                    result.push_back(root->val);
                    if(root->right)stk.push(root->right);
                    root=root->left;
                }
                else
                {
                    root=stk.top();
                    stk.pop();
                }
            }
            return result;
        }
};
