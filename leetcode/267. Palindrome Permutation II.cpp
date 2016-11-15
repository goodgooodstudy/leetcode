class Solution {
public:
    vector<string> generatePalindromes(string s) {
        map<char, int> cnt;
        for(char c : s) cnt[c]++;
        string left;
        int oddNum = 0;
        string odd = "";
        vector<string> rst;
        for(auto p:cnt){
            if(p.second%2 == 0){
                for(int k = 0; k < p.second/2; k++){
                    left.push_back(p.first);
                }
            }
            else{
                oddNum++;
                odd = p.first;
                if(oddNum > 1) return rst;
                if(p.second > 1){
                    for(int k = 0; k < p.second/2; k++ ){
                        left.push_back(p.first);
                    }
                }
            }
        }
        vector<bool> visited(left.size(), false);
        
        dfs(rst,"",visited, left, odd);
        return rst;
        
    }
    void dfs(vector<string>& rst, string path, vector<bool>& visited,  string left, string odd){
        if(path.size() == left.size()){
            string rev(path);
            reverse(rev.begin(), rev.end());
            rst.push_back(path+odd+rev);
            return;
        }
        for(int i = 0; i < left.size(); i++){
            if(i!=0 && left[i] == left[i-1] && visited[i-1]) continue;
            if(!visited[i]){
                visited[i] = true;
                path.push_back(left[i]);
                dfs(rst, path, visited, left, odd);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};
