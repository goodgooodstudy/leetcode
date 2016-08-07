class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0, m1 = 0, m2 =1;
        for(int n:nums){
            if(n == m1){
                cnt1++;
            }
            else if(n == m2){
                cnt2++;
            }
            else if(cnt1 ==0){
                m1 = n;
                cnt1=1;
            }
            else if(cnt2 == 0){
                m2 = n;
                cnt2 = 1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for(auto n:nums){
            if(n == m1)cnt1++;
            else if(n == m2)cnt2++;
        }
        vector<int> res;
        if(cnt1 > nums.size()/3) res.push_back(m1);
        if(cnt2 > nums.size()/3) res.push_back(m2);
        return res;
    }
};
