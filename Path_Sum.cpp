/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
O(N)
*/
class Solution {
    public:
        bool hasPathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)
            {
                return false;
            }
            if(root->left==NULL&&root->right==NULL)
            {
                return sum-root->val==0?true:false;
            }
            return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
        }
};
