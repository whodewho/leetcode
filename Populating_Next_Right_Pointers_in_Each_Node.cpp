/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/*
   again, anson have two better ideas.
   with the next link,  we can use bfs without extra space, awsome.
   what's more, dfs is also possible. thanks anson!
   every father node's next link is already filled. remember! 
 */
class Solution {
    public:
        /*
        void connect(TreeLinkNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return;
            vector<TreeLinkNode *> table[2];
            //vector<vector<TreeLinkNode *>> table(2);
            int cur=0,pre=1;
            table[cur].push_back(root);
            while(true)
            {
                cur=!cur;
                pre=!pre;
                table[cur].clear();
                for(int i=0;i<table[pre].size();i++)
                {
                    if(table[pre][i]->left!=NULL)
                    {
                        table[cur].push_back(table[pre][i]->left);
                        table[cur].push_back(table[pre][i]->right);
                    }
                }
                if(table[cur].empty())break;
                for(int i=0;i<table[cur].size()-1;i++)
                {
                    table[cur][i]->next=table[cur][i+1];
                }
            }
            return;
        }
        */
        //below are anson's solution
        void connect(TreeLinkNode *root)
        {
            //connect1(root);
            connect2(root);
        }

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

        void connect2(TreeLinkNode *node)
        {
            if (node) node->next = NULL;
            connectHelper2(node);
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
