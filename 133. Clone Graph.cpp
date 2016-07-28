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
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> cp;
        clone(node, cp);
        return cp[node];
    }
    UndirectedGraphNode* clone(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& cp){
        if(cp.count(node)) return cp[node];
        UndirectedGraphNode* cpnode = new UndirectedGraphNode(node->label);
        cp[node] = cpnode;
        for(auto neighbor : node->neighbors){
            cpnode->neighbors.push_back(clone(neighbor,cp));
        }
        return cpnode;
    }
};
