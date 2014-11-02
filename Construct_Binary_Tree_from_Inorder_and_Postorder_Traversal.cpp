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
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            return worker(inorder.begin(),postorder.begin(),inorder.size());
        }

        TreeNode *worker(vector<int>::iterator ii,vector<int>::iterator pi,int length)
        {
            if(length==0)return NULL;
            int newLength=find(ii,ii+length,*(pi+length-1))-ii;
            TreeNode *res=new TreeNode(pi[length-1]);
            res->left=worker(ii,pi,newLength);
            res->right=worker(ii+newLength+1,pi+newLength,length-newLength-1);
            return res;
        }
};
