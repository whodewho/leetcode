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
            // Note: The Solution object is instantiated only once and is reused by each test case.
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
                    if((j+1)%2!=0)return false;
                    while(i<j)
                    {
                        if (level[i] == NULL && level[j] != NULL||level[i] != NULL && level[j] == NULL)
                            return false;
                        if(!(level[i]==NULL&&level[j]==NULL)&&(level[i]->val != level[j]->val))
                            return false;
                        i++;
                        j--;
                    }

                    level.clear();
                    cur=nex;
                    nex=0;
                }
            }
            return true;
        }
};
