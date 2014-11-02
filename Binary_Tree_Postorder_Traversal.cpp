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
        vector<int> postorderTraversal(TreeNode *root) {
            vector<int> result;
            if(!root) return result;
            stack<TreeNode *> stk;
            while(!stk.empty()||root)
            {
                while(root)
                {
                    stk.push(root);
                    root=root->left;
                }

                if(!stk.empty()&&stk.top()->right&&(result.empty()||result.back()!=stk.top()->right->val))
                {
                    root=stk.top()->right;
                }
                else
                {
                    result.push_back(stk.top()->val);
                    stk.pop();
                    root=NULL;
                }
            }
            return result;
        }
};
