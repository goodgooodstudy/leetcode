class Solution {
    /*
    设置两个指针i, j, 一头一尾, 相向而行. 假设i指向的挡板较低, j指向的挡板较高(height[i] < height[j]).
    下一步移动哪个指针?
    -- 若移动j, 无论height[j-1]是何种高度, 形成的面积都小于之前的面积.
    -- 若移动i, 若height[i+1] <= height[i], 面积一定缩小; 但若height[i+1] > height[i], 面积则有可能增大.
    综上, 应该移动指向较低挡板的那个指针.
*/
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
