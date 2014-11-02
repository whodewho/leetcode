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
        
        ListNode *partition(ListNode *head, int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!head)return head;
            ListNode* less=NULL;
            ListNode* lessRunner=NULL;
            ListNode* great=NULL;
            ListNode* greatRunner=NULL;
            while(head)
            {
                if(head->val<x)
                {
                    if(!less)
                    {
                        less=head;
                    }
                    else
                    {
                        lessRunner->next=head;
                    }
                    lessRunner=head;
                    head=head->next;
                    lessRunner->next=NULL;
                }
                else
                {
                    if(!great)
                    {
                        great=head;
                    }
                    else
                    {
                        greatRunner->next=head;
                    }
                    greatRunner=head;
                    head=head->next;
                    greatRunner->next=NULL;
                }
            }

            if(less)
            {
                lessRunner->next=great;
                return less;
            }
            return great;
        }
};
