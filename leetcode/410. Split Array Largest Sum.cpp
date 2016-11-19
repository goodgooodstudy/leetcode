我们首先来分析，如果m和数组nums的个数相等，那么每个数组都是一个子数组，所以返回nums中最大的数字即可，
如果m为1，那么整个nums数组就是一个子数组，返回nums所有数字之和，所以对于其他有效的m值，返回的值必定在上面两个值之间，
所以我们可以用二分搜索法来做。
我们用一个例子来分析，nums = [1, 2, 3, 4, 5], m = 3，我们将left设为数组中的最大值5，right设为数字之和15，
然后我们算出中间数为10，我们接下来要做的是找出和最大且小于等于10的子数组的个数，[1, 2, 3, 4], [5]，可以看到我们无法分为3组，
说明mid偏大，所以我们让right=mid，然后我们再次进行二分查找哦啊，算出mid=7，再次找出和最大且小于等于7的子数组的个数，
[1,2,3], [4], [5]，我们成功的找出了三组，说明mid还可以进一步降低，我们让right=mid，然后我们再次进行二分查找哦啊，
算出mid=6，再次找出和最大且小于等于6的子数组的个数，[1,2,3], [4], [5]，我们成功的找出了三组，我们尝试着继续降低mid，
我们让right=mid，然后我们再次进行二分查找哦啊，算出mid=5，再次找出和最大且小于等于5的子数组的个数，[1,2], [3], [4], [5]，
发现有4组，此时我们的mid太小了，应该增大mid，我们让left=mid+1，此时left=6，right=5，循环退出了，我们返回left即可


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for(int n : nums){
            left = max(left, (long long)n);
            right += n;
        }
        while(left < right){
            long long mid = left + (right-left)/2;
            if(can_split(nums, m, mid)){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return left;
    }
    bool can_split(vector<int>& nums, int m, int sum){
        int cnt = 1;
        int curSum = 0;
        for(int i = 0; i < nums.size(); i++){
            curSum += nums[i];
            if(curSum > sum){
                cnt++;
                curSum = nums[i];
            }
            if(cnt > m) return false;

        }
        return true;
        
    }
};
