class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> rst;
        for(int i = 1; i <=9; i++){
            if(i <= n){
                dfs(rst, i, n);
            }
        }
        return rst;
    }
    void dfs(vector<int>& rst, int last, int n){
        if(last > n) return;
        rst.push_back(last);
        for(int i = 0; i <= 9; i++) dfs(rst, last*10+i,n);
    }
};
