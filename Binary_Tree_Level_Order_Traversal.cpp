/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//O(N)
//O(N)
   
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
                pre=!pre;
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

        vector<vector<int> > levelOrder(TreeNode *root) {
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
