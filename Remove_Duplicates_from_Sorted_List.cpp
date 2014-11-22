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
};
