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
   dfs is clear, bfs costs more code. however, you cannot avoid O(n).
 */
class Solution {
    public:
        int maxDepth(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > res;
            if(root==NULL)return 0;
            queue<TreeNode* > queue;
            vector<int> row;
            queue.push(root);
            int pre=1,cur=0,depth=0;
            while(!queue.empty())
            {
                TreeNode *item=queue.front();
                queue.pop();
                row.push_back(item->val);
                pre--;

                if(item->left)queue.push(item->left),cur++;
                if(item->right)queue.push(item->right),cur++;

                if(pre==0)
                {
                    depth++;
                    pre=cur;
                    cur=0;
                    row.clear();
                }
            }
            return depth;
        }

        int maxDepth2(TreeNode *root) {
            return maxDepthHelper2(root);
        }

        int maxDepthHelper2(TreeNode *node) {
            if (node == NULL) return 0;
            return 1+max(maxDepthHelper2(node->left), maxDepthHelper2(node->right));
        }
};
