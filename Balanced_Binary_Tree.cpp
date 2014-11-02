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
//O(1)

class Solution {
    public:
        bool isBalanced(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int depth=0;
            return worker(root,depth);
        }

        bool worker(TreeNode *root,int &depth)
        {
            if(root==NULL)
            {
                return true;
            }
            int ld=0,rd=0;
            if(!worker(root->left,ld))return false;
            if(!worker(root->right,rd))return false;

            depth=max(ld,rd)+1;
            return abs(ld-rd)<=1;
        }
};
