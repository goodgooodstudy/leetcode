class Solution {
private:
    vector<int> root;
    int findroot(int node){
        if(root[node] == node) return node;
        root[node] =  findroot(root[node]);
        return root[node];
    }
    void unionnodes(int node1, int node2){
        root[findroot(node1)] = findroot(node2);
    }
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        for(int i = 0; i < n; i++) root.push_back(i);
        for(auto pair : edges){
            unionnodes(pair.first, pair.second);
        }
        set<int> cnt;
        for(int i = 0; i <n; i++){
            cnt.insert(findroot(i));
        }
        return cnt.size();
        
    }
};
