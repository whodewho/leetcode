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
        
        int minDepth(TreeNode *root) {
            if(!root)return 0;
            if(root->left==NULL&&root->right==NULL)return 1;
            int result=1, tl=INT_MAX, tr=INT_MAX;
            if(root->left)tl=minDepth(root->left);
            if(root->right)tr=minDepth(root->right);
            return 1+min(tl, tr);
        }

        int minDepth(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return 0;
            int res=1;
            vector<vector<TreeNode* >> table(2);
            int pre=0,cur=1;
            table[cur].push_back(root);
            while(true)
            {
                cur=!cur;
                pre=!pre;
                table[cur].clear();
                bool sign=false;
                for(int i=0;i<table[pre].size();i++)
                {
                    if(table[pre][i]->left==NULL&&table[pre][i]->right==NULL)
                    {
                        sign=true;
                        break;
                    }
                    if(table[pre][i]->left)table[cur].push_back(table[pre][i]->left);
                    if(table[pre][i]->right)table[cur].push_back(table[pre][i]->right);
                }
                if(sign)break;
                res++;
            }
            return res;
        }
};
