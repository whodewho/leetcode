/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/*
  O(N)
 */
class Solution {
    public:
        void connect1(TreeLinkNode *node)
        {
            if (node) node->next = NULL;
            connectHelper1(node);
        }

        // BFS
        void connectHelper1(TreeLinkNode* node) {
            if (!node || !(node->left) || !(node->right)) return;
            TreeLinkNode* curr = node;
            while (curr) {
                if (curr->left) curr->left->next = curr->right;
                if (curr->right) curr->right->next = (curr->next) ? curr->next->left : NULL;
                curr = curr->next;
            }   
            connectHelper1(node->left);
        }   

        // DFS
        void connectHelper2(TreeLinkNode* node) {
            if (!node || !(node->left) || !(node->right)) return;
            node->left->next = node->right;
            node->right->next = (node->next) ? node->next->left: NULL;
            connectHelper2(node->left);
            connectHelper2(node->right);
        }
};
