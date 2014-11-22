/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //O(N)

class Solution {
    public:
        ListNode *removeNthFromEnd(ListNode *head, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!head)return NULL;
            int i=0;
            ListNode* runner=head;
            ListNode* father=NULL;
            while(runner)
            {
                runner=runner->next;
                if(i<n)i++;
                else
                {
                    if(father)
                        father=father->next;
                    else
                        father=head;
                }
            }
            if(father==NULL)
            {
                ListNode* toReturn=head->next;
                delete head;
                return toReturn;
            }
            else
            {
                ListNode* toDelete=father->next;
                father->next=toDelete->next;
                delete toDelete;
                return head;
            }
        }
};
