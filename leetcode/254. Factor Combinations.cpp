class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> rst;
        vector<int> cur;
        helper(n, rst, cur);
        return rst;
    }
    void helper(int n, vector<vector<int>>& rst, vector<int> cur){
        int i = cur.size() == 0? 2: cur.back();
        for(; i <= n/i; i++){
            if(n%i == 0){
                cur.push_back(i);
                cur.push_back(n/i);
                rst.push_back(cur);
                cur.pop_back();
                helper(n/i, rst, cur);
                cur.pop_back();
            }
        }
    }
};
