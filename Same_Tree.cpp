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
   can be less?
   yes...second is anson's solution
 */
class Solution {
    public:
        bool isSameTree(TreeNode *p, TreeNode *q) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!p&&!q)return true;
            else if(p&&q)
            {
                if(p->val!=q->val)return false;
                return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
            }
            return false;
        }

        bool isSameTree(TreeNode *p, TreeNode *q) {
            if (p == NULL || q == NULL) return p == q;
            if (p->val != q->val) return false;
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
};
