/**
    We can't just spit this into subquestions by passing the child pointer for recursion. 
    We need a new method which can keep the status when we enter the child tree. Reference is a good choice.
    Whenever we the algorithm come to a leaf, it should add the path sum to the final result.
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //O(N)
class Solution {
    public:
        int sumNumbers(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> path;
            int sum=0;
            if(root==NULL)
                return 0;
            sumNumbersWorker(root,0,sum);
            return sum;
        }

        void sumNumbersWorker(TreeNode *root, int now, int &sum)
        {
            now+=root->val;
            if(root->left==NULL&&root->right==NULL)
            {
                sum+=now;
                return;
            }
            now*=10;
            if(root->left)sumNumbersWorker2(root->left,now,sum);
            if(root->right)sumNumbersWorker2(root->right,now,sum);
        }
};
