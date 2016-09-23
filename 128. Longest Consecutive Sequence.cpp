class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx = 1;
        unordered_map<int, int>cnt;
        for(auto n : nums) {
            cnt[n]++;
        }
        for(pair<int, int> p : cnt){
            if(p.second >0){

                 int l = p.first-1;
                while(cnt.count(l) && cnt[l] >0){
                    cnt[l]--;
                    l--;
                }
                int r = p.first;
                while(cnt.count(r) && cnt[r] >0){
                    cnt[r]--;
                    r++;
                }

                mx = max(mx, r-l-1);
            }

        }
        return mx;
    }
};
