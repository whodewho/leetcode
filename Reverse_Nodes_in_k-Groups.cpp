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
        ListNode *reverseKGroup(ListNode *head, int k) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode* result=NULL;
            ListNode* last=NULL;
            ListNode* start=head;
            while(start)
            {
                int i=0;
                ListNode* end=start;
                while(i<k&&end)
                {
                    end=end->next;
                    i++;
                }

                if(i<k)break;

                i=0;
                ListNode* tmpStart=NULL;
                ListNode* tmpEnd=NULL;
                while(i<k)
                {
                    if(tmpStart==NULL)
                    {
                        tmpStart=start;
                        tmpEnd=start;
                        start=start->next;
                    }
                    else
                    {
                        ListNode* tmp=start->next;
                        start->next=tmpStart;
                        tmpStart=start;
                        start=tmp;
                    }
                    i++;
                }

                if(result==NULL)result=tmpStart;
                if(last==NULL)last=tmpEnd;
                else
                {
                    last->next=tmpStart;
                    last=tmpEnd;
                }
                last->next = start;
            }

            if(result==NULL)return head;
            return result;
        }
};
