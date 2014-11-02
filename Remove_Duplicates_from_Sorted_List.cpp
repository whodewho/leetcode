/*
O(N)
 */
class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
            if (NULL == head) return NULL;
            ListNode* curNode = head;
            while(NULL != curNode->next) {
                if(curNode->val == curNode->next->val) {
                    ListNode* nextNode = curNode->next;
                    curNode->next = nextNode->next;
                    delete nextNode;
                }
                else curNode = curNode->next;
            }
            return head;
        }

        ListNode *deleteDuplicates(ListNode *head) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(!head)return head;
            ListNode* result=head;

            while(head)
            {
                if(head->next)
                {
                    if(head->val==head->next->val)
                    {
                        ListNode* tmp=head->next;
                        head->next=head->next->next;
                        delete tmp;
                        continue;
                    }
                }
                head=head->next;
            }

            return result;
        }
};
