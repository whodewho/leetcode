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
    the second solution, bfs, does not work. leetcode is mad today. i can't see the input of wrong answer.
    need to fix the bug later. anson, you are lazy this time.
   */
class Solution {
    public:
        bool isSymmetric(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return true;
            return worker(root->left,root->right);
        }

        bool worker(TreeNode * lchild,TreeNode * rchild)
        {
            if(lchild==NULL||rchild==NULL)return lchild==rchild;
            if(lchild->val!=rchild->val)return false;
            return worker(lchild->left,rchild->right)&&worker(lchild->right,rchild->left);
        }

        bool isSymmetric(TreeNode *root) {
            // Start typing your C/C++ solution below
            if(root==NULL)return true;
            queue<TreeNode *> queue;
            int cur=1,nex=0;
            queue.push(root);
            vector<TreeNode *> level;

            while(!queue.empty())
            {
                TreeNode *front=queue.front();
                queue.pop();
                cur--;

                if(front->left)queue.push(front->left),nex++;
                level.push_back(front->left);
                if(front->right)queue.push(front->right),nex++;
                level.push_back(front->right);

                if(cur==0)
                {
                    int i=0,j=level.size()-1;
                    while(i<j)
                    {
                        if(level[i++]!=level[j--])return false;
                    }

                    level.clear();
                    cur=nex;
                    cur=0;
                }
            }
            return true;
        }
};
