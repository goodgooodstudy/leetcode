class Solution {
public:
//  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
//     set<int> window; // set is ordered automatically 
//     for (int i = 0; i < nums.size(); i++) {
//         if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
//         // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
//         auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
//         // x - nums[i] <= t ==> |x - nums[i]| <= t    
//         if (pos != window.end() && *pos - nums[i] <= t) return true;
//         window.insert(nums[i]);
//     }
//     return false;
// }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> windows;
        for(int i = 0; i < nums.size(); i++){
            if(i > k) windows.erase(nums[i-k-1]);
            long long low = 0;
            long long up = 0;
            low = low + nums[i]-t;
            up = up + nums[i] + t;
            // cout << up<<endl;
            auto it = windows.lower_bound( low);
            // if(it != windows.end() && *it - nums[i]<= t)return true; //*it <= nums[i]+t overflow
            if(it != windows.end() && *it <= up)return true; //*it <= nums[i]+t overflow

            windows.insert(nums[i]);
        }
        return false;
        
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> rst;
        for(int i = 0; i < nums.size(); i++){
            if(i>k) rst.erase(nums[i-k-1]);
            auto lower = rst.lower_bound(nums[i]-t);
            if(lower != rst.end()){
                if(abs(nums[i]-*lower) <=t) return true;
            }
            rst.insert(nums[i]);
        }
        return false;
        
    }
};
