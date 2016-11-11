/**
* @Author: lcy
* @Date:   2016-09-03T12:50:54-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



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

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> dict;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        queue<UndirectedGraphNode*> q;
        unordered_set<UndirectedGraphNode*> visited;
        if(node) q.push(node);
        else return NULL;
        visited.insert(node);
        dict[node] = new UndirectedGraphNode(node->label);
        while(!q.empty()){
            UndirectedGraphNode* cur = q.front();
            q.pop();

            for(auto neigh : cur->neighbors){
                if(!dict.count(neigh)){
                    dict[neigh] = new UndirectedGraphNode(neigh->label);
                }
                dict[cur]->neighbors.push_back(dict[neigh]);
                if(!visited.count(neigh)){
                    q.push(neigh);
                    visited.insert(neigh); //有可能已经在queue里面但是没pop出来，如果再pop时候判断，就可能in queue了两次。可以用dictpanduan
                }
            }
        }
        return dict[node];

    }
};


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> dict;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        queue<UndirectedGraphNode*> q;
        if(node) q.push(node);
        else return NULL;
        dict[node] = new UndirectedGraphNode(node->label);
        while(!q.empty()){
            UndirectedGraphNode* cur = q.front();
            q.pop();

            for(auto neigh : cur->neighbors){
                if(!dict.count(neigh)){
                    dict[neigh] = new UndirectedGraphNode(neigh->label);
                    q.push(neigh);

                }
                dict[cur]->neighbors.push_back(dict[neigh]);

            }
        }
        return dict[node];

    }
};
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
private:
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> dict;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        return clone(node);

    }
    UndirectedGraphNode* clone(UndirectedGraphNode* node){
        if(dict.count(node)) return dict[node];
        dict[node] = new UndirectedGraphNode(node->label);
        for(auto neigh : node->neighbors){
            dict[node]->neighbors.push_back(clone(neigh));
        }
        return dict[node];
    }
};
