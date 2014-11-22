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
   garfield try, same with first try
   follow instinction
   I can do it!
   */

//O(N)

class Solution {
	public:
		
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
