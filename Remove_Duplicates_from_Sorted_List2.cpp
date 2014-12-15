/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
O(N)
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
                        ListNode* tmpHead=head;
                        head=head->next;                        
                        delete tmpHead;
                    }while(head!=NULL&&head->val==tmp);
                }
                else
                {
                    if(newHead==NULL)
                    {
                        newHead=head;
                    }
                    else
                    {
                        newCurr->next=head;
                    }
                    newCurr=head;
                    head=head->next;
                    newCurr->next=NULL;
                }
            }
            return newHead;
        }
};
