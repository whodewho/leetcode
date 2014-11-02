/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
   O(N*N*M)
   使用堆或者队列，可以更快O(log(N)*N*M)
*/
class Solution {
    public:

        ListNode *mergeKLists(vector<ListNode *> &lists) 
        {
            ListNode* result=NULL;
            ListNode* tail=NULL;
            while(true)
            {
                int minIndex = -1;
                int minValue = INT_MAX;
                for(int i=0;i<lists.size();i++)
                {
                    if(lists[i])
                    {
                        if(lists[i]->val<minValue)
                        {
                            minIndex=i;
                            minValue=lists[i]->val;
                        }
                    }
                    else
                    {
                        lists.erase(lists.begin()+i);
                        i--;
                    }
                }
                
                if(minIndex==-1)
                    return result;
                
                for(int i=0;i<lists.size();i++)
                {
                    if(lists[i]&&lists[i]->val==minValue)
                    {
                        ListNode* tmp=lists[i];
                        lists[i]=lists[i]->next;
                        tmp->next=NULL;
                        
                        if(result)
                        {
                            tail->next=tmp;
                            tail=tmp;
                        }
                        else
                        {
                            result=tmp;
                            tail=tmp;
                        }
                    }
                }
            }
        }
};
