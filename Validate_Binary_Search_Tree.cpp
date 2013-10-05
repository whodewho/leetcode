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
   the first solution is mine, the rest three are anson's.
   mine is about same with his first, light difference.
   INT_MIN, INI_MAX, yes, than he applied floor and ceil. This is O(n).
   I thought of this too, but I do not know this tow constants until now.
   as his third solution, in-order wolk and check if it is no-decreasing.
   smart.
 */
class Solution {
    public:
        bool isValidBST(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return true;

            return validRight(root->right,root->val)
                &&validLeft(root->left,root->val)
                &&isValidBST(root->left)
                &&isValidBST(root->right);
        }

        bool validRight(TreeNode* root,int father)
        {
            if(root==NULL)return true;
            return root->val>father&&validRight(root->left,father)&&validRight(root->right,father);
        }

        bool validLeft(TreeNode *root,int father)
        {
            if(root==NULL)return true;
            return root->val<father&&validLeft(root->left,father)&&validLeft(root->right,father);
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

        bool isValidBST(TreeNode *root) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            TreeNode* preNode=NULL;
            return inOrder(root,preNode);
        }

        // pre-order walk with looking up min and max
        // takes O(n*log(n)) time
        bool isValidBST1(TreeNode* node) {
            if (node == NULL) return true;
            if (maxVal(node->left) < node->val && node->val < minVal(node->right)) {
                return isValidBST1(node->left) && isValidBST1(node->right);
            }
            return false;
        }

        int minVal(TreeNode* node) {
            if (node == NULL) return INT_MAX;
            while (node->left != NULL) node = node->left;
            return node->val;
        }

        int maxVal(TreeNode* node) {
            if (node == NULL) return INT_MIN;
            while (node->right != NULL) node = node->right;
            return node->val;
        }

        // pre-order walk with updating min and max
        // takes O(n) time
        bool isValidBST2(TreeNode* node) {
            return isValidBSTHelper2(node, INT_MIN, INT_MAX);
        }

        bool isValidBSTHelper2(TreeNode* node, int min, int max) {
            if (node == NULL) return true;
            if (min  < node->val && node->val < max) {
                return isValidBSTHelper2(node->left, min, node->val)
                    && isValidBSTHelper2(node->right, node->val, max);
            }
            return false;
        }

        // in-order walk and check if it is no-decreasing
        // takes O(n) time
        bool isValidBST3(TreeNode* node) {
            int prev = INT_MIN;
            return isValidBSTHelper3(node, prev);
        }

        bool isValidBSTHelper3(TreeNode* node, int &prev) {
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
};
