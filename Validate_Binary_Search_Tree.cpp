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
        
        bool isValidBST(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            TreeNode* preNode=NULL;
            return inOrder(root,preNode);
        }

        //second try, almost same with anson's last one
        bool inOrder(TreeNode* currNode,TreeNode* &preNode)
        {
            if(!currNode)return true;

            if(!inOrder(currNode->left,preNode))return false;
            if(preNode&&preNode->val>=currNode->val)return false;
            preNode=currNode;
            if(!inOrder(currNode->right,preNode))return false;
            return true;
        }

        // in-order walk and check if it is no-decreasing
        // takes O(n) time
        bool isValidBST(TreeNode* node) {
            int prev = INT_MIN;
            return isValidBSTHelper3(node, prev);
        }

        bool isValidBSTHelper(TreeNode* node, int &prev) {
            if (node == NULL) return true;
            if (isValidBSTHelper3(node->left, prev)) {
                if (prev < node->val) {
                    prev = node->val;
                    return isValidBSTHelper3(node->right, prev);
                }
                return false;
            }
            return false;
        }

        // pre-order walk with updating min and max
        // takes O(n) time
        bool isValidBST(TreeNode* node) {
            return isValidBSTHelper2(node, INT_MIN, INT_MAX);
        }

        bool isValidBSTHelper(TreeNode* node, int min, int max) {
            if (node == NULL) return true;
            if (min  < node->val && node->val < max) {
                return isValidBSTHelper2(node->left, min, node->val)
                    && isValidBSTHelper2(node->right, node->val, max);
            }
            return false;
        }
};
