class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<unordered_set<int>> graph = make_graph(numCourses,prerequisites);
        vector<int> degrees = fill_in(numCourses,graph);
        queue<int>q;
        vector<int>res;
        int count = 0;
        for(int i = 0; i < numCourses; i++){
            if(degrees[i]==0)q.push(i);
        }
        while(q.size()!=0){
            count++;
            int cur = q.front();
            res.push_back(cur);
            q.pop();
            for(int neighbor:graph[cur]){
                if(--degrees[neighbor]==0)q.push(neighbor);
            }
            
        }
        if(count!=numCourses)return vector<int>(0);
        return res;
        
    }
    vector<unordered_set<int>> make_graph(int numCourses,vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> res(numCourses);
        for(auto p:prerequisites){
            res[p.second].insert(p.first);
        }
        return res;
    }
    vector<int> fill_in(int numCourses,vector<unordered_set<int>>& graph){
            vector<int> res(numCourses,0);
            for(int i = 0; i < numCourses; i++){
                for(auto next:graph[i]){
                    res[next]++;
                }
            }
            return res;
        }
    
    
};
