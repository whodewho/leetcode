/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 /*
O(N)
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *result=NULL;
        RandomListNode *runner=NULL;
        RandomListNode *runnerHead=head;
        map<RandomListNode*, RandomListNode*> m;
        while(runnerHead)
        {
            RandomListNode* tmp=new RandomListNode(runnerHead->label);
            m[runnerHead]=tmp;
            if(result)
                runner->next=tmp;
            else
                result=tmp;
            runner=tmp;
            runnerHead=runnerHead->next;
        }
        
        runner=result;
        runnerHead=head;
        while(runner)
        {
            runner->random=m[runnerHead->random];
            runner=runner->next;
            runnerHead=runnerHead->next;
        }
        return result;
    }
};