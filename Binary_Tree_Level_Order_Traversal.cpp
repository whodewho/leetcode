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
   met before. several times.
   the first solution is mine, the rest are anson's.
   anson's first solution is not smart, too many times down to bottom.
   his second solution is almost same as mine, he use two queue, i don't see swap a good choice. by the way, I learned my solution from him too.
   his third solution, ok, is the best one. he keeps the number of nodes of pre level and cur level. ok, back to solution two... 
   don't use tmp anymore.....
   leetcode is hot now. server always busy.
 */
class Solution {
    public:
        vector<vector<int> > levelOrder(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int>> res;
            if(root==NULL)return res;
            vector<vector<TreeNode*>> table(2);
            int pre=0,cur=1;
            table[cur].push_back(root);
            vector<int> tmp;
            tmp.push_back(root->val);
            res.push_back(tmp);
            while(true){
                cur=!cur;
                pre=!cur;
                table[cur].clear();
                vector<int> tmp;
                for(int i=0;i<table[pre].size();i++)
                {
                    if(table[pre][i]->left)
                    {
                        table[cur].push_back(table[pre][i]->left);
                        tmp.push_back(table[pre][i]->left->val);
                    }
                    if(table[pre][i]->right)
                    {
                        table[cur].push_back(table[pre][i]->right);
                        tmp.push_back(table[pre][i]->right->val);
                    }
                }
                if(table[cur].empty())break;
                res.push_back(tmp);
            }
            return res;
        }

        vector<vector<int> > levelOrder(TreeNode *root) {
            return levelOrder1(root);
        }

        vector<vector<int> > levelOrder1(TreeNode *root) {
            vector<vector<int> > res;
            vector<int> row;
            for (int level = 1; level <= maxHeight(root); level++) {
                row.clear();
                levelOrderHelper1(root, level, row);
                res.push_back(row);
            }
            return res;
        }

        int maxHeight(TreeNode *node) {
            if(NULL == node) return 0;
            return 1 + max(maxHeight(node->left), maxHeight(node->right));
        };

        void levelOrderHelper1(TreeNode *node, int level, vector<int> &row) {
            if (level == 0 || node == NULL) return;
            if (level == 1) {
                row.push_back(node->val);
                return;
            }
            levelOrderHelper1(node->left, level-1, row);
            levelOrderHelper1(node->right, level-1, row);
        }

        vector<vector<int> > levelOrder2(TreeNode *root) {
            vector<vector<int> > res;
            vector<int> row;
            queue<TreeNode*> currQ, nextQ;
            if (root) currQ.push(root);
            while (!currQ.empty()) {
                row.clear();
                while (!currQ.empty()) {
                    TreeNode* front = currQ.front();
                    currQ.pop();
                    row.push_back(front->val);
                    if (front->left) nextQ.push(front->left);
                    if (front->right) nextQ.push(front->right);
                }
                swap(currQ, nextQ);
                res.push_back(row);
            }
            return res;
        }

        vector<vector<int> > levelOrder3(TreeNode *root) {
            vector<vector<int> > res;
            vector<int> row;
            queue<TreeNode*> currQ;
            int currNum = 1, nextNum = 0;
            if (root) currQ.push(root);
            while (!currQ.empty()) {
                TreeNode* front = currQ.front();
                currQ.pop(), currNum--;
                row.push_back(front->val);
                if (front->left) currQ.push(front->left), nextNum++;
                if (front->right) currQ.push(front->right), nextNum++;
                if (currNum == 0) {
                    res.push_back(row);
                    row.clear();
                    currNum = nextNum;
                    nextNum = 0;
                }
            }
            return res;
        }
};
