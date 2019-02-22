class Solution {
private:
    map<int, int> dict;
    int total;
public:
    Solution(vector<int> w) {
        total = 0;
        for(int i = 0; i < w.size(); i++){
            total += w[i];
            dict[total] = i;
        }
    }
    
    int pickIndex() {
        int idx= rand()%total;
        return dict.upper_bound(idx)->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
