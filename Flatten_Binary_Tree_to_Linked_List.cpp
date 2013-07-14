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
    first time, I thought I came up with a solution better than anson's.
    the second is clear, but neet more whiles.
    the first is more efficient, but use return value, more complicated
   */
class Solution {
    public:
        void flatten(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return;
            worker(root);
            return;
        }
        TreeNode *worker(TreeNode *root){
            if(root->left==NULL&&root->right==NULL)return root;
            if(root->left)
            {
                TreeNode* lleave=worker(root->left);
                TreeNode* rleave=lleave;
                if(root->right)
                {
                    rleave=worker(root->right);
                    lleave->right=root->right;
                }
                root->right=root->left;
                root->left=NULL;
                return rleave;
            }
            else if(root->right)
            {
                return worker(root->right);
            }
        }

        //more time need
        void flatten(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return;
            flatten(root->right);
            if(root->left)
            {
                flatten(root->left);

                TreeNode *leaf=root->left;
                while(leaf->right)
                {
                    leaf=leaf->right;
                }
                leaf->right=root->right;
                root->right=root->left; 
                root->left=NULL;
            }
        }
};
