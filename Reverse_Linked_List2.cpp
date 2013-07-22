/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
    from anson.
    can't be better.
    when you spend too much time on one question, it's time to seek a solution.
    don't be too silly, get stuck in interview like this, you already suck.  
   */
class Solution {
    public:
        ListNode *reverseBetween(ListNode *head, int m, int n) {
            if (head == NULL || head->next == NULL) return head;
            ListNode *preTail = NULL, *curTail = NULL;
            ListNode *preNode = NULL, *curNode = head;
            for (int i = 1; i <= n; i++) {
                if (i == m-1) preTail = curNode;
                if (i == m) curTail = curNode;
                if (i >= m) {
                    ListNode* nextNode = curNode->next;
                    curNode->next = preNode;
                    preNode = curNode;
                    curNode = nextNode;
                }
                else curNode = curNode->next;
            }
            if (preTail == NULL) head = preNode;
            else preTail->next = preNode;
            curTail->next = curNode;
            return head;
        }
};
