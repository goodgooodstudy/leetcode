class Solution {
public:
    string originalDigits(string s) {
        vector<int> cnt(128, 0);
        for(char c : s) cnt[c] ++;
        vector<int> nums(10,0);
        nums[0] = cnt['z'];
        nums[1] = cnt['o']-cnt['z']-cnt['w']-cnt['u'];
        nums[2] = cnt['w'];
        nums[3] = cnt['h']-cnt['g'];
        nums[4] = cnt['u'];
        nums[5] = cnt['f'] - cnt['u'];
        nums[6] = cnt['x'];
        nums[7] = cnt['s']-cnt['x'];
        nums[8] = cnt['g'];
        nums[9] = cnt['i']-cnt['f']+cnt['u']-cnt['x']-cnt['g'];
        string rst;
        for(int i = 0; i < 10; i++){
            for(int k = 0; k < nums[i]; k++){
                rst+=to_string(i);
            }
        }
        return rst;
        
        
        
    }
};
