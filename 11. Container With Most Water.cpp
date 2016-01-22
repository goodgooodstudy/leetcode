class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxS = INT_MIN;
        int i = 0, j = height.size()-1;
        while(i<j){
            maxS = max(maxS, min(height[i],height[j])* (j-i));
            if(height[i] < height[j]){
                i++;
            }
            else
                j--;
            
            
        }
        return maxS;
        
    }
};
