/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
   n*m
   */
class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            ListNode* result=NULL;
            ListNode* runner=NULL;
            while(true)
            {
                ListNode* tmpLink=NULL;
                int min=INT_MAX,tmpIndex=0;
                for(size_t i=0;i<lists.size();i++)
                {
                    if(lists[i])
                    {
                        if(lists[i]->val<min)
                        {
                            min=lists[i]->val;
                            tmpIndex=i;
                            tmpLink=lists[i];
                        }
                    }
                }
                if(tmpLink==NULL)break;
                else
                {
                    if(result==NULL)
                    {
                        result=tmpLink;
                    }
                    else
                    {
                        runner->next=tmpLink;
                    }
                    runner=tmpLink;
                    lists[tmpIndex]=lists[tmpIndex]->next;
                }
            }
            return result;
        }
};
