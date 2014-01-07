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
		ListNode *insertionSortList(ListNode *head) {
			if (!head)
				return head;
			ListNode* nHead = head;
			head = head->next;
			nHead->next = NULL;
			while (head) {
				ListNode* runner = nHead;
				if (runner->val > head->val) {
					ListNode* tmp = head->next;
					head->next = nHead;
					nHead = head;
					head = tmp;
					continue;
				}

				while (runner->next && runner->next->val < head->val) {
					runner = runner->next;
				}
				if (!runner->next) {
					ListNode* tmp = head->next;
					runner->next = head;
					head->next = NULL;
					head = tmp;
				} else {
					ListNode* tmp = head->next;
					head->next = runner->next;
					runner->next = head;
					head = tmp;
				}
			}
			return nHead;
		}
};
