class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;
        vector<vector<int>> hold(n, vector<int>(3,0));
        vector<vector<int>> unhold(n, vector<int>(3,0));

        for(int k = 0; k < 3; k++){
            hold[0][k] = - prices[0];
            unhold[0][k] = 0;
        }
        for(int i = 0; i < n; i++){
            hold[i][0] = -prices[0];
            unhold[i][0] = 0;
        }
        for(int i= 1; i < n; i++){
            for(int k = 1; k < 3; k++){
                hold[i][k] = max(unhold[i-1][k-1]-prices[i],hold[i-1][k]);
                unhold[i][k] = max(hold[i-1][k]+prices[i], unhold[i-1][k]);
            }
        }
        return unhold[n-1][2];
    }
};
class Solution {
public:
/*
解释：
首先，因为能买2次（第一次的卖可以和第二次的买在同一时间），但第二次的买不能在第一次的卖左边。
所以维护2个表，f1和f2，size都和prices一样大。
意义：
f1[i]表示 -- 截止到i下标为止，左边所做交易能够达到最大profit；
f2[i]表示 -- 截止到i下标为止，右边所做交易能够达到最大profit；
那么，对于f1 + f2，寻求最大即可。
*/
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int size = prices.size();
        if (size == 0)
            return 0;

        vector<int> f1(size);
        vector<int> f2(size);

        int minV = prices[0];
        for (int i = 1; i < size; i++){
            minV = std::min(minV, prices[i]);
            f1[i] = std::max(f1[i-1], prices[i] - minV);
        }

        int maxV = prices[size-1];
        f2[size-1] = 0;
        for (int i = size-2; i >= 0; i--){
            maxV = std::max(maxV, prices[i]);
            f2[i] = std::max(f2[i+1], maxV - prices[i]);
        }

        int sum = 0;
        for (int i = 0; i < size; i++)
            sum = std::max(sum, f1[i] + f2[i]);

        return sum;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<2) return 0;
        int minPrice=prices[0];
        int maxProfit = 0;
        vector<int> leftProfit(n,0);
        for(int i = 1; i<n;i++){
            minPrice=min(minPrice,prices[i]);
            maxProfit=max(maxProfit,prices[i]-minPrice);
            leftProfit[i]=maxProfit;
        }
        int maxPrice = prices[n-1];
        maxProfit = 0;
        int ret = 0;
        for(int i = n-2; i>=0;i--){
            maxPrice = max(maxPrice,prices[i]);
            maxProfit=max(maxProfit,maxPrice-prices[i]);
            ret=max(ret,leftProfit[i]+maxProfit);
        }
        return ret;

    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        else{
            int maxProfit = 0;
            int K = 2;
            vector<vector<int>> f(K+1, vector<int>(prices.size(), 0));
            for(int kk = 1; kk <= K; kk++){
                int tmp = f[kk-1][0] - prices[0];
                for(int ii = 1; ii <prices.size(); ii++){
                    f[kk][ii] = max(f[kk][ii-1], prices[ii]+tmp);
                    tmp = max(tmp, f[kk-1][ii]-prices[ii]);
                    maxProfit = max(maxProfit, f[kk][ii]);
                }
            }
            return maxProfit;


        }

    }
};
