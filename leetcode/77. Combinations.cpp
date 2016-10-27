class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmp;
        dfs(result,n, tmp, 0, k);
        return result;
        
        
    }
    void dfs(vector<vector<int>>& result, int n, vector<int>current, int start,int k ){

        if(current.size() == k) {
            result.push_back(current);
            return;
        }
        for (int i = start+1; i <=n ; i++){
            current.push_back(i);
            dfs(result, n, current,i,k );
            current.pop_back();
        }
    }
};
