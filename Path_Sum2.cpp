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
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > res;
            if(root==NULL)return res;
            vector<int> path;
            worker(root,sum,res,path);
            return res;
        }

        void worker(TreeNode *root,int sum,vector<vector<int>> &res,vector<int> path)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                if(sum-root->val==0)
                {
                    path.push_back(root->val);
                    res.push_back(path);
                }
                return;
            }
            path.push_back(root->val);
            if(root->left)worker(root->left,sum-root->val,res,path);
            if(root->right)worker(root->right,sum-root->val,res,path);
            path.pop_back();        
        }
};
