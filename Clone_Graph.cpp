/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    public:

        UndirectedGraphNode *worker(UndirectedGraphNode *node,map<int, UndirectedGraphNode*> &copied)
        {
            map<int,UndirectedGraphNode*>::iterator it=copied.find(node->label);
            if(it==copied.end())
            {
                UndirectedGraphNode *newNode=new UndirectedGraphNode(node->label);
                copied.insert(pair<int,UndirectedGraphNode*>(newNode->label,newNode));
                for(size_t i=0;i<node->neighbors.size();i++)
                {
                    UndirectedGraphNode *neighbor=worker(node->neighbors[i],copied);
                    newNode->neighbors.push_back(neighbor);
                }
                return newNode;
            }
            return copied[node->label];
        }

        UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if(node==NULL)return NULL;
            map<int,UndirectedGraphNode*> copied;
            return worker(node,copied);
        }
};
