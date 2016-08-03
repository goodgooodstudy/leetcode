class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;

        vector<int> buy(n,0);
        buy[0] = - prices[0];
        buy[1] = max(-prices[0],-prices[1]);
        vector<int> sell(n,0);
        sell[1] = max(buy[0]+prices[1],0);
        for(int i = 2; i<n; i++){
            buy[i] = max(sell[i-2]-prices[i],buy[i-1]); //replace vector with three variables
            sell[i] = max(buy[i-1]+prices[i],sell[i-1]);
        }
        return sell[n-1];
        
    }
};
