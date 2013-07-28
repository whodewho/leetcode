/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    checked anson's, delete, yeah, impressive
    but my is clearer.
   */
class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode* newHead=NULL;
            ListNode* newCurr=NULL;
            if(head==NULL)return NULL;
            while(head)
            {
                if(head->next&&head->val==head->next->val)
                {
                    int tmp=head->val;
                    do
                    {
                        //delete head
                        head=head->next;
                    }while(head!=NULL&&head->val==tmp);
                }
                else
                {
                    if(newHead==NULL)
                    {
                        newHead=head;
                        newCurr=head;
                    }
                    else
                    {
                        newCurr->next=head;
                        newCurr=head;
                    }
                    head=head->next;
                    newCurr->next=NULL;
                }
            }
            return newHead;
        }
};
