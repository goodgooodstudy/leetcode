class Solution {
public:
/*klogK*/
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       vector<pair<int, int>> res;
       if(min(k,int(nums1.size()*nums2.size()))<=0) return res;
       auto cmp = [&nums1, &nums2](pair<int, int>a, pair<int, int>b){return nums1[a.first]+nums2[a.second] >nums1[b.first]+nums2[b.second]; };
       priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minheap(cmp);
       minheap.emplace(0,0);
       while(k-- >0 && minheap.size()){
           auto idx_pair = minheap.top();minheap.pop();
           res.emplace_back(nums1[idx_pair.first],nums2[idx_pair.second]);
           if(idx_pair.first+1<nums1.size()){
               minheap.emplace(idx_pair.first+1,idx_pair.second);
           }
           if(idx_pair.first == 0 && idx_pair.second+1 < nums2.size()){
               minheap.emplace(idx_pair.first,idx_pair.second+1);
           }
       }
       return res;
       
       
    }
};


class Solution {
public:
/*m*n*logK*/
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>>res;
        priority_queue<pair<int,int>, vector<pair<int, int>>, cmp>q;
        for(int i = 0; i<min(k,(int)nums1.size()); i++){
            for(int j = 0; j < min(k, (int)nums2.size()); j++){
                if(q.size() < k){
                    q.emplace(nums1[i],nums2[j]);
                }
                else if(nums1[i]+nums2[j] < q.top().first+q.top().second){
                    q.pop();
                    q.emplace(nums1[i],nums2[j]);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.top());
            q.pop();
        }
        return res;
       
    }
    struct cmp{
        bool operator()(pair<int, int>&a, pair<int,int>&b){
            return a.first+a.second < b.first+b.second;
        }
    };
    // vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    //   vector<pair<int, int>> res;
    //   if(min(k,int(nums1.size()*nums2.size()))<=0) return res;
    //   auto cmp = [&nums1, &nums2](pair<int, int>a, pair<int, int>b){return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second]; };
    //   priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minheap(cmp);
    //   minheap.emplace(0,0);
    //   while(k-- >0 && minheap.size()){
    //       auto idx_pair = minheap.top();minheap.pop();
    //       res.emplace_back(nums1[idx_pair.first],nums2[idx_pair.second]);
    //       if(idx_pair.first+1<nums1.size()){
    //           minheap.emplace(idx_pair.first+1,idx_pair.second);
    //       }
    //       if(idx_pair.first == 0 && idx_pair.second+1 < nums2.size()){
    //           minheap.emplace(idx_pair.first,idx_pair.second+1);
    //       }
    //   }
    //   return res;
       
       
    // }
};
