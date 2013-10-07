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

   look at my second try, no as good as first one
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


        ListNode *deleteDuplicates(ListNode *head) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(!head)return head;

            ListNode* runner=head;
            ListNode* newHead=NULL;
            ListNode* tail=NULL;
            ListNode* pre=NULL;

            while(runner)
            {
                if(pre==NULL)
                {
                    pre=runner;
                    runner=runner->next;
                }
                else
                {
                    while(runner && pre->val==runner->val)
                    {
                        runner=runner->next;
                    }

                    if(pre->next==runner)
                    {
                        if(newHead==NULL)
                        {
                            newHead=pre;
                        }
                        else
                        {
                            tail->next=pre;
                        }
                        tail=pre;
                    }
                    pre=NULL;
                }
            }

            if(newHead)
            {
                tail->next=pre;
                return newHead;
            }
            else return pre;
        }
};
