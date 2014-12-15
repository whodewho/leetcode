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
		ListNode *swapPairs(ListNode *head) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			ListNode* result=NULL;
			ListNode* last=NULL;
			while(head)
			{
				if(head->next)
				{
					ListNode* tmp=head->next;
					head->next=tmp->next;
					tmp->next=head;

					if(result==NULL)
					{
						result=tmp;
					}
					else
					{
						last->next=tmp;
					}
					last=head;
				}
				else
				{
					if(result==NULL)
					{
						result=head;
					}
					else
					{
						last->next=head;
					}
				}
				head=head->next;
			}
			return result;
		}
};
