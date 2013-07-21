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
    anson's solution.
    inorder travel, the first node was initialized once and all.
    the second node was the last bad node, compared with the first node.
    that's all....
   */
class Solution {
    public:
        void recoverTree(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            TreeNode *prev = NULL, *first = NULL, *second = NULL;
            recoverTreeHelper(root, prev, first, second);
            swap(first->val, second->val);
        }

        void recoverTreeHelper(TreeNode *curNode, TreeNode *&preNode, TreeNode *&first, TreeNode *&second) {
            if (curNode == NULL) return;
            recoverTreeHelper(curNode->left, preNode, first, second);
            if (preNode && preNode->val > curNode->val) {
                if (first == NULL) first = preNode;
                second = curNode;
            }
            preNode = curNode;
            recoverTreeHelper(curNode->right, preNode, first, second);
        }

};
