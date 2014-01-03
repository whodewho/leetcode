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
        ListNode *detectCycle(ListNode *head) {
            if(!head) return NULL;
            ListNode* fRunner = head;
            ListNode* sRunner = head;

            while(true)
            {
                fRunner = fRunner->next;
                if(!fRunner)return NULL;
                fRunner = fRunner->next;
                if(!fRunner)return NULL;
                sRunner = sRunner->next;
                if(sRunner==fRunner)break;
            }

            ListNode* tRunner = head;
            while(tRunner != fRunner)
            {
                tRunner=tRunner->next;
                fRunner=fRunner->next;
            }
            return tRunner;
        }
};
