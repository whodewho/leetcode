/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        void reorderList(ListNode *head) {
            if(!head)return;
            ListNode* sRunner = head;
            ListNode* fRunner = head;
            while(true)
            {
                fRunner=fRunner->next;
                if(!fRunner)break;
                fRunner=fRunner->next;
                if(!fRunner)break;
                sRunner=sRunner->next;
            }

            ListNode* nHead=NULL;
            ListNode* nRunner=sRunner->next;
            sRunner->next=NULL;

            while(nRunner)
            {
                ListNode* tmp = nRunner->next;
                nRunner->next = nHead;
                nHead = nRunner;
                nRunner = tmp;
            }

            ListNode* result = NULL;
            while(head)
            {
                if(!result) result=head;
                else    result->next=head;
                result = head;
                head = head->next;

                result->next = nHead;
                if(nHead)
                {   
                    result = nHead;
                    nHead=nHead->next;
                }
            }
        }
};
