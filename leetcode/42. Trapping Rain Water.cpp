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
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        stack<int> sk;
        int mx = 0;
        for(int i = 0; i <height.size(); ){
            if(sk.empty() || height[i] <= height[sk.top()] ){
                sk.push(i++); // keep left smaller is all pop out
            }
            else{
                int l = sk.top();
                sk.pop();
                int cur = 0;
                if(sk.empty()) cur = 0;
                else cur = (min(height[sk.top()], height[i])-height[l])*(i-sk.top()-1);
                mx += cur;
            }
        }
        return mx;
    }
};
