/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    the second one the anson's solution. his is better.
    his 'while' is better. 
    he used three arguments, saving one iteration each recursion.
    mine is O(n*n), dame it.
    but, his is just a little faster than mine.
   */
class Solution {
    public:
        TreeNode *sortedListToBST(ListNode *head) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(head==NULL)return NULL;
            int length=0;
            ListNode* tmp=head;
            while(tmp)
            {
                tmp=tmp->next;
                length++;
            }
            return worker(head,length);
        }

        TreeNode *worker(ListNode *head,int length){
            if(length==1)
            {
                return new TreeNode(head->val);
            }
            if(length<1)return NULL;
            int i=1;
            ListNode* mid=head;
            while(i<ceil(length/2.0))
            {
                mid=mid->next;
                i++;   
            }
            TreeNode *res=new TreeNode(mid->val);
            res->left=worker(head,i-1);
            res->right=worker(mid->next,length-i);
            return res;
        }

        TreeNode *sortedListToBST(ListNode *head) {
            if (head == NULL) return NULL;
            ListNode* node = head;
            int len = 1;
            while (NULL != (node = node->next)) len++;
            return sortedListToBSTHelper(head, 0, len - 1);
        }

        // in-order build tree, takes O(n) time
        TreeNode* sortedListToBSTHelper(ListNode*& head, int start, int end) {
            if (start > end) return NULL;
            int mid = start + (end - start) / 2;
            TreeNode* leftTree = sortedListToBSTHelper(head, start, mid - 1);
            TreeNode* root = new TreeNode(head->val);
            root->left = leftTree;
            head = head->next;
            root->right = sortedListToBSTHelper(head, mid + 1, end);
            return root;
        };
};
