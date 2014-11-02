/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//O(N)

class Solution {
    public:
        ListNode *rotateRight(ListNode *head, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!head)return head;
            if(!k)return head;

            ListNode* runner=head;
            int num=0;
            while(runner)
            {
                num++;
                runner=runner->next;
            }
            k=k%num;
            if(!k)return head;

            runner=head;
            while(k--)
                runner=runner->next;
            ListNode* newTail=head;
            while(runner->next!=NULL)
            {
                runner=runner->next;
                newTail=newTail->next;
            }
            ListNode* res=newTail->next;
            newTail->next=NULL;
            runner->next=head;
            return res;
        }
};
