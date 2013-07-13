/*
    which one as reference? which one as return value? 
    set the global value as reference! cake problem, but i worried too much.
   */
class Solution {
    public:
        int maxPathSum(TreeNode *root) 
        {
            if (root == NULL) return 0;
            int maxSoFar = root->val;
            maxPathSumHelper(root, maxSoFar);
            return maxSoFar;
        }

        int maxPathSumHelper(TreeNode *node, int &maxSoFar)
        {
            if (node == NULL) return 0;
            int leftMax = maxPathSumHelper(node->left, maxSoFar);
            int rightMax = maxPathSumHelper(node->right, maxSoFar);
            int maxPath = node->val;
            if (leftMax > 0)  maxPath += leftMax;
            if (rightMax > 0) maxPath += rightMax;
            if (maxPath > maxSoFar) maxSoFar = maxPath; 
            int res = node->val;
            return max(res, res+max(leftMax, rightMax));
        }
/*
        int maxPathSum(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            pair<int,int> res=worker(root);
            return res.first;
        }

        pair<int,int> worker(TreeNode *root)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                return make_pair(root->val,root->val);
            }
            else if(root->left!=NULL&&root->right!=NULL)
            {
                pair<int,int>left=worker(root->left);
                pair<int,int>right=worker(root->right);
                int res=root->val,path=root->val;
                if(max(left.second,right.second)>0)
                {
                    path+=max(left.second,right.second);
                }
                if(left.second>0)res+=left.second;
                if(right.second>0)res+=right.second;
                res=max(max(left.first,right.first),res);
                return make_pair(res,path);
            }
            else if(root->left!=NULL&&root->right==NULL)
            {
                pair<int,int>left=worker(root->left);
                int res=root->val,path=root->val;
                if(left.second>0)
                {
                    path+=left.second;
                }
                if(left.second>0)res+=left.second;
                res=max(left.first,res);
                return make_pair(res,path);
            }
            else if(root->left==NULL&&root->right!=NULL)
            {
                pair<int,int>right=worker(root->right);
                int res=root->val,path=root->val;
                if(right.second>0)
                {
                    path+=right.second;
                }
                if(right.second>0)res+=right.second;
                res=max(right.first,res);
                return make_pair(res,path);
            }
        }
        */
};
