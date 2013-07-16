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
   can it be more succient? let me see anson's.
   ok, his arguments is better.second is his solution.
   mine is more c!
 */
class Solution {
    public:
        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            return worker(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        }

        TreeNode *worker(vector<int> &preorder,int low1,int high1,vector<int> &inorder,int low2,int high2)
        {
            if(low1>high1)return NULL;
            TreeNode *res=new TreeNode(preorder[low1]);
            int midIndex=find(inorder.begin()+low2,inorder.begin()+high2,preorder[low1])-inorder.begin();
            res->left=worker(preorder,low1+1,low1+midIndex-low2,inorder,low2,midIndex-1);
            res->right=worker(preorder,low1+midIndex-low2+1,high1,inorder,midIndex+1,high2);
            return res;
        }

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
