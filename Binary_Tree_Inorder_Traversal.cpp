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
    the second solution is anson's. 
    my iterative version is almost same, but not work, so, it's different.
   */
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> res;
            worker(root,res);
            return res;
        }

        void worker(TreeNode* root,vector<int> &vec)
        {
            if(root==NULL)return;
            worker(root->left,vec);
            vec.push_back(root->val);
            worker(root->right,vec);
        }

        vector<int> inorderTraversal(TreeNode *node) {
            vector<int> result;
            if (node == NULL) return result;
            stack<TreeNode*> stk;
            TreeNode* curr = node;
            while (!stk.empty() || curr != NULL) {
                if (curr != NULL) {
                    stk.push(curr);
                    curr = curr->left;
                }
                else {
                    curr = stk.top();
                    stk.pop();
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
            return result;
        }
};
