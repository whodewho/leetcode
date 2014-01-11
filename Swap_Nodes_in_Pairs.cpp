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
						last=head;
					}
					else
					{
						last->next=tmp;
						last=head;
					}
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

		ListNode *swapPairs(ListNode *head) {
			ListNode* result=NULL;
			ListNode *runner=NULL;

			while(head)
			{
				ListNode* first=head;
				ListNode* second=head->next;
				if(second==NULL)
				{
					if(runner)runner->next=head;
					else result=head;
					break;
				}
				ListNode* third=second->next;

				if(result==NULL)
				{
					result=second;
					second->next=first;
					first->next=NULL;
					runner=first;
				}
				else
				{
					runner->next=second;
					second->next=first;
					first->next=NULL;
					runner=first;
				}

				head=third;
			}
			return result;
		}
};
