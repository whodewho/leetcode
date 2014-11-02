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
    the first solution is anson's. yes, it clearer!
    however, this solution cost more space. the same subtree may be generated for many times. 
    in my solution, the same subtree just build once and copy several times.
    the second is mine. 
    all in all, the idea are same.
   */
    
//O(2^N) F(N)=F(0)+F(N-1) + F(1)+F(N-2)... F(N-1)+F(0)

//O(N^2)
    
class Solution {
    public:

        vector<TreeNode *> generateTrees(int n) {
            return generateTreesHelper(1, n);
        }

        vector<TreeNode*> generateTreesHelper(int l, int u) {
            vector<TreeNode*> res;
            if (l > u) {
                res.push_back(NULL);
                return res;
            }
            for (int k = l; k <= u; k++) {
                vector<TreeNode*> leftTrees = generateTreesHelper(l, k-1);
                vector<TreeNode*> rightTrees = generateTreesHelper(k+1, u);
                for (size_t i = 0; i < leftTrees.size(); i++) {
                    for (size_t j = 0; j < rightTrees.size(); j++) {
                        TreeNode* root = new TreeNode(k);
                        root->left = leftTrees[i];
                        root->right = rightTrees[j];
                        res.push_back(root);
                    }
                }
            }
            return res;
        }


        vector<TreeNode *> generateTrees(int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<TreeNode *>> res;
            vector<TreeNode *>result;
            result.push_back(NULL);
            if(n==0)return result;

            res.push_back(result);
            for(int i=1;i<=n;i++)
                worker(i,res);
            return res[n];
        }

        void worker(int n,vector<vector<TreeNode *>> &res)
        {
            vector<TreeNode *> result;
            if(n==1)
            {
                result.push_back(new TreeNode(1));
                res.push_back(result);
                return;
            }

            for(int j=1;j<=n;j++)
            {
                vector<TreeNode *> leftChild;
                vector<TreeNode *> rightChild;

                if(j==1)
                {
                    vector<TreeNode *>rightChild=copy(j,res[n-j]);
                    for(int k=0;k<rightChild.size();k++)
                    {
                        TreeNode* item=new TreeNode(j);
                        item->right=rightChild[k];
                        result.push_back(item);
                    }
                    continue;
                }
                else if(j==n)
                {
                    vector<TreeNode *>leftChild=res[n-1];
                    for(int k=0;k<leftChild.size();k++)
                    {
                        TreeNode *item=new TreeNode(j);
                        item->left=leftChild[k];
                        result.push_back(item);
                    }
                    continue;
                }

                leftChild=res[j-1];
                rightChild=copy(j,res[n-j]);

                for(int t=0;t<leftChild.size();t++)
                {
                    for(int k=0;k<rightChild.size();k++)
                    {
                        TreeNode *item=new TreeNode(j);
                        item->left=leftChild[t];
                        item->right=rightChild[k];
                        result.push_back(item);
                    }
                }
            }
            res.push_back(result);
            return;
        }


        vector<TreeNode *> copy(int n,vector<TreeNode* >&res)
        {
            vector<TreeNode *> result;
            for(int i=0;i<res.size();i++)
            {
                result.push_back(copyOne(n,res[i]));
            }
            return result;
        }

        TreeNode *copyOne(int n,TreeNode *root)
        {
            if(root==NULL)return NULL;
            TreeNode *item=new TreeNode(root->val+n);
            item->left=copyOne(n,root->left);
            item->right=copyOne(n,root->right);
            return item;
        }

};
