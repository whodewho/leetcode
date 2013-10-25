/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
   second try, seems better
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

        ListNode *reverseKGroup(ListNode *head, int k) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(!head)return head;
            if(k==1)return head;

            int num=0;
            ListNode* runner=head;
            while(runner)
            {
                num++;
                runner=runner->next;
            }
            if(num<k)return head;

            ListNode* result=NULL;
            ListNode* tail=NULL;

            for(int i=0;i<num/k;i++)
            {
                ListNode* newTail=head;
                ListNode* newHead=head;
                head=head->next;
                for(int j=1;j<k;j++)
                {
                    ListNode* tmp=head->next;
                    head->next=newHead;
                    newHead=head;
                    head=tmp;
                }
                if(!result)result=newHead;
                if(tail)tail->next=newHead;
                tail=newTail;
                tail->next=head;
            }

            return result;
        }
};
