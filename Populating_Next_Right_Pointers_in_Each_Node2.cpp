/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/*
   a slight change of question one will work on this.
   the second two does't work. shit how did I upload them here
   check anson's,his is right

   can be done with O(1), at youdao, save it for you
 */
class Solution {
    public: 
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
                    }
                    if(table[pre][i]->right!=NULL)
                    {
                        table[cur].push_back(table[pre][i]->right);
                    }
                }
                if(table[cur].empty())break;
                for(int i=0;i<table[cur].size()-1;i++)
                {
                    table[cur][i]->next=table[cur][i+1];
                }
            }
        }

        /*
        //bfs with less space 
        void connect(TreeLinkNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return;
            TreeLinkNode *node=root;
            while(node)
            {
                if(node->left)
                {
                    if(node->right)node->left->next=node->right;
                    else if(node->next&&node->next->left)node->left->next=node->next->left;
                    else if(node->next&&node->next->right)node->left->next=node->next->right;
                }
                if(node->right)
                {
                    if(node->next&&node->next->left)node->right->next=node->next->left;
                    else if(node->next&&node->next->right)node->right->next=node->next->right;
                }
                node=node->next;
            }
            if(root->left)connect(root->left);
            else if(root->right)connect(root->right);
        }

        //dfs new
        void connect(TreeLinkNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(root==NULL)return;
            TreeLinkNode *node=root;

            if(node->left)
            {
                if(node->right)node->left->next=node->right;
                else if(node->next&&node->next->left)node->left->next=node->next->left;
                else if(node->next&&node->next->right)node->left->next=node->next->right;
            }
            if(node->right)
            {
                if(node->next&&node->next->left)node->right->next=node->next->left;
                else if(node->next&&node->next->right)node->right->next=node->next->right;
            }

            if(root->left)connect(root->left);
            if(root->right)connect(root->right);
        }
        */
};
