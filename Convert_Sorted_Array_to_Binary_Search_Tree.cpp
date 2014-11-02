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
        TreeNode *sortedArrayToBST(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            return worker(num,0,num.size()-1);
        }

        TreeNode * worker(vector<int> &num,int low,int high)
        {
            if(low>high)return NULL;
            int mid=(low+high)/2;
            TreeNode *root=new TreeNode(num[mid]);
            root->left=worker(num,low,mid-1);
            root->right=worker(num,mid+1,high);
            return root;
        }
};
