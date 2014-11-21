/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 /*
O(N) O(N)

O(N) O(1), if there is a circle, you are doomed, don't do it.
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


   
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *newHead=NULL;
        RandomListNode *newRunner=NULL;
        RandomListNode *runner=head;

        while(runner)
        {
            RandomListNode *tmp=new RandomListNode(runner->label);
            if(newHead==NULL)newHead=tmp;
            else newRunner->next=tmp;
            newRunner=tmp;

            runner=runner->next;
        }

        runner=head;
        newRunner=newHead;
        while(runner)
        {
            RandomListNode *tmp=runner->random;
            runner->random=newRunner;
            newRunner->random=tmp;

            runner=runner->next;
            newRunner=newRunner->next;
        }

        runner=head;
        newRunner=newHead;
        set<RandomListNode*> copied;
        while(runner)
        {
            if(copied.find(runner)==copied.end())
            {
                RandomListNode *oldRandom=newRunner->random;
                if(oldRandom)
                {
                    RandomListNode *newRandom=oldRandom->random;
                    if(newRandom&&newRandom->random==runner)
                    {
                        //pair node random to each other
                        //can't unlink the first node's random, for the second node will lost
                        runner->random=oldRandom;
                        oldRandom->random=runner;
                        newRunner->random=newRandom;
                        newRandom->random=newRunner;
                        copied.insert(runner);
                        copied.insert(oldRandom);
                    }
                    else
                    {
                        runner->random=oldRandom;
                        newRunner->random=newRandom;
                    }
                }
                else
                {
                    runner->random=NULL;
                }
            }
    
            runner=runner->next;
            newRunner=newRunner->next;
        }

        return newHead;
    }
};