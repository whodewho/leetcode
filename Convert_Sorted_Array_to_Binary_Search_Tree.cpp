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
   array, that's easy. the middle of the array is the root node.

   the second try, cost more space
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

        TreeNode *sortedArrayToBST(vector<int> &num) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(num.empty())return NULL;

            int n=num.size();
            TreeNode* result=new TreeNode(num[n/2]);
            if(n/2-1>=0)
            {
                vector<int> l(num.begin(),num.begin()+n/2);
                result->left=sortedArrayToBST(l);
            }
            if(n/2+1<n)
            {
                vector<int> r(num.begin()+n/2+1,num.end());
                result->right=sortedArrayToBST(r);
            }
            return result;
        }
};
