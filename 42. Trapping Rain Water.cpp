class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> max_left(height.size(), 0);
        vector<int> max_right(height.size(), 0);
        int n = height.size();
        for(int i = 1; i<n; i++){
            max_left[i] = max(max_left[i-1], height[i-1]);
            max_right[n-1-i] = max(max_right[n-i], height[n-i]);
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            int h = min(max_left[i], max_right[i]);
            if(h > height[i]){
                sum += h - height[i];
            }
        }
        return sum;
    }
};
