class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.empty()) return 0;
        int days = prices.size();
        if( k > days>>1) return maxProfit2(k,prices);
        vector<vector<int>> hold(days,vector<int>(k+1,0));
        vector<vector<int>> unhold(days,vector<int>(k+1,0));
        hold[0][0] = -prices[0];
        for(int i = 1; i < days;i++){
            hold[i][0] = max(hold[i-1][0],-prices[i]);
            // unhold[i][0] = 0;
            
        }
        for(int i = 1; i <= k;i++){
            hold[0][i] = -prices[0];
            // unhold[0][i] = 0;
        }

        for(int i = 1; i < days; i++){
            for(int j = 1; j <= k; j++){
                hold[i][j] = max(hold[i-1][j], unhold[i-1][j]-prices[i]);
                unhold[i][j] = max(unhold[i-1][j], hold[i-1][j-1]+prices[i]);
            }
        }
        return unhold[days-1][k];
        
    }
    int maxProfit2(int k, vector<int>& prices){
        int profit = 0;
        for(int i = 1; i<prices.size();i++){
            if(prices[i] > prices[i-1])profit+=prices[i]-prices[i-1];
        }
        return profit;
    }
};
