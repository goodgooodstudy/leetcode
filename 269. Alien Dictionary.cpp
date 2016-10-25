class Solution {
private:
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> degrees;
    bool make_graph(vector<string>& words){
        for(int i = 1; i < words.size(); i++){
            string w1 = words[i-1], w2 = words[i];
            bool found = false;
            int l1 = w1.size(), l2 = w2.size(), l = max(l1,l2);
            for(int j = 0; j < l; j++){
                if(j < l1 && !graph.count(w1[j])){
                    graph[w1[j]] = unordered_set<char>();
                }
                if(j < l2 && !graph.count(w2[j])){
                    graph[w2[j]] = unordered_set<char>();
                }
                if(!found && j < l1 && j < l2 && w1[j]!=w2[j]){
                    graph[w1[j]].insert(w2[j]);
                    found = true;
                }
                if(!found && j > l2){
                        return false;
                } 
                
            }
 
        }
        return true;
    }
    
    void make_degrees(){
        for(auto r : graph){
            if(!degrees.count(r.first)) degrees[r.first] = 0;
            for(char next: r.second){
                ++degrees[next];
            }
        }
    }
    
public:
    
    string alienOrder(vector<string>& words) {
        if(words.size() == 1) return words[0];
        if(!make_graph(words)) return "";
        make_degrees();
        
        queue<char> q;
        for(auto letter : degrees){
            if(letter.second == 0){
                q.push(letter.first);
            } 
        }
        int cnt = 0;
        string res;
        while(!q.empty()){
            char cur = q.front();
            res += cur;
            q.pop();
            cnt ++;
            for(auto neigh: graph[cur]){
                
                if(--degrees[neigh] == 0){
                    q.push(neigh); 
                }
            }
        }
        if(cnt != degrees.size()) return "";
        return res;
        
    }
};
