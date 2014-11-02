//O(N)
//O(1)

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
};
