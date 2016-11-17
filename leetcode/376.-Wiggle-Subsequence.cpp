class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int n = nums.size();
        vector<int> up(n, 0);
        vector<int> down(n,0);
        up[0] = 1;
        down[0] = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                up[i] = down[i-1]+1;
                down[i] = down[i-1];
            }
            else if(nums[i] < nums[i-1]){
                down[i] = up[i-1]+1;
                up[i] = up[i-1];
             }
             else{
                 down[i] = down[i-1];
                 up[i] = up[i-1];
             }
        }
        return max(down[n-1], up[n-1]);
    }
};
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        vector<int> dp(n,1);
        dp[0] = 1;
        vector<int> sign(n,1);
        int m = 1;
        for(int i = 1; i < n; i++){
            for(int j = i-1; j >= 0; j--){
                if( (j==0 || sign[j]>0)  && nums[i] > nums[j] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    sign[i] = -1;

                }
                else if((j==0 || sign[j] < 0) && nums[i] < nums[j] && dp[j]+1 >dp[i]){
                    dp[i] = dp[j]+1;
                    sign[i] = 1;

                }

            }
            m = max(m,dp[i]);
        }

        return m;
    }
};

/*
摇摆序列要求升高，降低，升高。。。

或者降低，升高，降低。。。

那么我们只要找出数组中的“拐点” 即可 举个例子:

4 5 6  3 2 1这几个数中，4为起点，那么5和6中，我们肯定选6啊~因为之后的数要求小于5，小于5的必定也小于6 比如改为4 5 6 5，之前要是选5就没办法继续往下了。。

总之就是选最小的和选最大的（也就是拐点） 保证不丢最优解。
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int ans = 1;
        for(int i =0, j=1; j < nums.size(); i = j, j++){
            if(nums[j] > nums[i]){
                ans++;
                while(j+1 < nums.size() && nums[j+1] >= nums[j])j++;
            }
            else if(nums[j] < nums[i]){
                ans++;
                while(j+1<nums.size() && nums[j+1] <= nums[j])j++;
            }
        }
        return ans;

    }
};
