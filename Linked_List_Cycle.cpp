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
        bool hasCycle(ListNode *head) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if(!head)return false;
            ListNode* fRunner=head;
            ListNode* sRunner=head;

            while(true)
            {
                fRunner=fRunner->next;
                if(!fRunner)return false;
                fRunner=fRunner->next;
                if(!fRunner)return false;
                sRunner=sRunner->next;
                if(sRunner==fRunner)return true;
            }
        }
};
