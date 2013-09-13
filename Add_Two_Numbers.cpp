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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if(!l1)return l2;
            if(!l2)return l1;
            int carry=0;
            ListNode * result=NULL;
            ListNode * runner=NULL;
            while(l1&&l2)
            {
                if(result==NULL)
                {
                    result= new ListNode((l1->val+l2->val)%10);
                    carry=(l1->val+l2->val)/10;
                    runner=result;
                }
                else
                {
                    runner->next=new ListNode((l1->val+l2->val+carry)%10);
                    carry=(l1->val+l2->val+carry)/10;
                    runner=runner->next;
                }
                l1=l1->next;
                l2=l2->next;
            }

            ListNode *rest=l1?l1:l2;
            while(rest)
            {
                runner->next=new ListNode((rest->val+carry)%10);
                carry=(rest->val+carry)/10;
                runner=runner->next;
                rest=rest->next;
            }
            if(carry)
                runner->next=new ListNode(carry);

            return result;
        }
};
