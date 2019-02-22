class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto it = upper_bound(arr.begin(), arr.end(), x);
        int idx = (it == arr.end()) ? arr.size() : it-arr.begin();
        int idx2 = idx-1;
        vector<int> rst2;
        vector<int> rst1;
        vector<int> rst;

        while(k-->0){
            double l = idx2 >= 0 ? arr[idx2]: (double)INT_MIN-1;
            double r = idx < arr.size() ? arr[idx] : (double)INT_MAX+1;
            if(x -l <= r -x){
                rst1.push_back(arr[idx2--]);
            }else{
                rst2.push_back(arr[idx++]);
            }
            
        }
        reverse(rst1.begin(), rst1.end());
        for(int n : rst1) rst.push_back(n);
        for(int n : rst2) rst.push_back(n);
        return rst;
    }
};
