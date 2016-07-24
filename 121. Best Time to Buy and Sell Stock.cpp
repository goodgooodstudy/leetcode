class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int minimal = prices[0];
        int profit = INT_MIN;
        for(auto p : prices){
            minimal = min(p, minimal);
            profit = max(profit, p - minimal);
        }
        return profit;
    }
};
