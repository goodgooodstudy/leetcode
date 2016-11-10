class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for(int n : nums) cnt[n]++;
        auto cmp = [](pair<int,int> a, pair<int,int> b){return a.second > b.second;};
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for(auto p : cnt){
            if(q.size() < k ){
                q.push(p);
            }
            else if(p.second > q.top().second){
                q.push(p); //unordered_map 里面（p）就是pair了。。。
                q.pop();
            }
        }
        vector<int> rst;
        while(!q.empty()){
            auto cur =q.top();
            rst.push_back(cur.first);
            q.pop();
        }
        return rst;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>cnt;
        for(auto n:nums){
            cnt[n]++;
        }
        auto cmp = [](pair<int,int>&a,pair<int,int>&b){return a.second>b.second;};
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> q(cmp);
        for(auto &x: cnt){

            if(q.size()<k){
                q.emplace(x.first,x.second);
            }
            else{
                if(x.second > q.top().second){
                    q.pop();
                    q.emplace(x.first,x.second);

                }
            }
        }
        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
