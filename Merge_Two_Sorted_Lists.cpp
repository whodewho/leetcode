/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    O(M+N)
   */
class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!l1)return l2;
            if(!l2)return l1;

            ListNode * head=NULL;
            ListNode * runner=NULL;
            while(l1&&l2)
            {
                if(l1->val<=l2->val)
                {
                    if(!head)
                    {
                        head=l1;
                        runner=l1;
                    }
                    else
                    {
                        runner->next=l1;
                        runner=l1;
                    }
                    l1=l1->next;
                }
                else
                {
                    if(!head)
                    {
                        head=l2;
                        runner=l2;
                    }
                    else
                    {
                        runner->next=l2;
                        runner=l2;
                    }
                    l2=l2->next;
                }
            }
            runner->next=l1==NULL?l2:l1;
            return head;
        }
};
