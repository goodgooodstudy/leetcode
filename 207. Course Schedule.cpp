class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.empty())return true;
        vector<unordered_set<int>> graph = make_graph(numCourses,prerequisites);
        vector<int> degrees = fill_degree(numCourses,graph);
        for(int i=0; i < numCourses; i++){
            int j = 0;
            for(; j < numCourses;j++){
                if(degrees[j]==0)break;
            }
            if(j == numCourses)return false;
            degrees[j] = -1;
            for(auto neighbor:graph[j]){
                degrees[neighbor]--;
            }
        }
        return true;
        
    }
    vector<unordered_set<int>> make_graph(int numCourses,vector<pair<int, int>>& prerequisites){
        vector<unordered_set<int>> graph(numCourses);
        for(auto pair: prerequisites){
            graph[pair.second].insert(pair.first);
        }
        return graph;
    }
    vector<int> fill_degree(int numCourses,vector<unordered_set<int>>& graph){
        vector<int> degrees(numCourses,0);
        for(int i=0; i<numCourses; i++ ){
            for(auto neighbor: graph[i]){
                degrees[neighbor]++;
            }
        }
        return degrees;
    }
};
