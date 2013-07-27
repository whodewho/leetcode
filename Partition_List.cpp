/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    have checked anson's, his is clear, mine is faster.
    when curr->val<x, no need to prev->next=curr
   */
class Solution {
    public:
        ListNode *partition(ListNode *head, int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode* curr=head;
            ListNode* oldHead=NULL;
            ListNode* prev=NULL;
            ListNode* newHead=NULL;
            ListNode* newCurr=NULL;
            while(curr)
            {
                if(curr->val<x)
                {
                    if(oldHead==NULL)oldHead=curr;
                    prev=curr;
                    curr=curr->next;
                }
                else
                {
                    if(newHead==NULL)
                    {
                        newHead=curr;
                        newCurr=curr;
                    }
                    else
                    {
                        newCurr->next=curr;
                        newCurr=curr;
                    }
                    if(prev!=NULL)prev->next=curr->next;
                    curr=curr->next;
                    newCurr->next=NULL;
                }

            }
            if(oldHead!=NULL)
            {
                prev->next=newHead;
                head=oldHead;
            }else
            {
                head=newHead;
            }
            return head;
        }
};
