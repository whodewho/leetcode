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
class Solution {
    public:
        int sumNumbers(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> path;
            int sum=0;
            if(root==NULL)
                return 0;
            //sumNumbersWorker1(root,path,sum);
            sumNumbersWorker2(root,0,sum);
            return sum;
        }

        void sumNumbersWorker1(TreeNode *root,vector<int>& path,int &sum)
        {
            path.push_back(root->val);
            if(root->left==NULL&&root->right==NULL)
            {
                sum+=calculate(path);
            }
            if(root->left)sumNumbersWorker1(root->left,path,sum); 
            if(root->right)sumNumbersWorker1(root->right,path,sum);
            path.pop_back();
        }

        int calculate(vector<int> &path)
        {
            int sum=0;
            for(vector<int>::iterator it=path.begin();it!=path.end();it++)
            {
                sum=sum*10+*it;
            }
            return sum;
        }

        void sumNumbersWorker2(TreeNode *root, int now, int &sum)
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
