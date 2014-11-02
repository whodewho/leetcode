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
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > res;
            if(root==NULL)return res;
            queue<TreeNode* > queue;
            vector<int> row;
            queue.push(root);
            int pre=1,cur=0,direction=1;
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
                    pre=cur;
                    cur=0;
                    if(direction)
                        res.push_back(row);
                    else
                    {
                        reverse(row.begin(),row.end()),res.push_back(row);
                    }
                    row.clear();
                    direction=!direction;
                }
            }
            return res;
        }

        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            vector<vector<int> > res;
            if (root == NULL) return res;
            vector<int> row;
            stack<TreeNode*> currS, nextS;
            currS.push(root);
            bool leftToRight = true;
            while (!currS.empty()) {
                while (!currS.empty()) {
                    TreeNode* front = currS.top();
                    currS.pop();
                    row.push_back(front->val);
                    if (leftToRight) {
                        if (front->left) nextS.push(front->left);
                        if (front->right) nextS.push(front->right);
                    }
                    else {
                        if (front->right) nextS.push(front->right);
                        if (front->left) nextS.push(front->left);
                    }
                }
                res.push_back(row);
                row.clear();
                swap(currS, nextS);
                leftToRight = !leftToRight;
            }
            return res;
        }

};
