/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//quicksort, O(N*N)
class Solution {
	public:
		ListNode *sortList(ListNode *head) {
			if(!head)return head;
			ListNode* middle=head;
			head=head->next;
			if(!head)return middle;
			middle->next=NULL;

			ListNode* small=NULL;
			ListNode* big=NULL;
			while(head)
			{
				if(head->val<middle->val)
				{
					ListNode* tmp=head->next;
					head->next=small;
					small=head;
					head=tmp;
				}
				else if(head->val>middle->val)
				{
					ListNode* tmp=head->next;
					head->next=big;
					big=head;
					head=tmp;
				}else
				{
					ListNode* tmp=head->next;
					head->next=middle;
					middle=head;
					head=tmp;
				}
			}

			ListNode* result=middle;
			if(small)
			{
				ListNode* smallSort=sortList(small);
				ListNode* runner=smallSort;
				while(runner->next)runner=runner->next;
				runner->next=middle;
				result=smallSort;
			}
			while(middle->next)middle=middle->next;
			middle->next=sortList(big);
			return result;
		}
};
