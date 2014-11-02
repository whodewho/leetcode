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

        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            return buildTreeHelper(preorder.begin(), inorder.begin(), preorder.size());
        }

        TreeNode *buildTreeHelper(vector<int>::iterator preorder, vector<int>::iterator inorder, size_t n) {
            if (n == 0) return NULL;
            vector<int>::iterator it = find(inorder, inorder + n, *preorder);
            int idx = it - inorder;
            TreeNode* root = new TreeNode(*it);
            root->left = buildTreeHelper(preorder+1, inorder, idx);
            root->right = buildTreeHelper(preorder+idx+1, inorder+idx+1, n-idx-1);
            return root;
        }
};
