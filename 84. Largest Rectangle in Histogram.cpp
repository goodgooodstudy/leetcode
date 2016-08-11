class Solution {
    public:
        int largestRectangleArea(vector<int> &height) {
            
            int ret = 0;
            height.push_back(0);
            stack<int> index;
            for(int i = 0; i < height.size(); i++){
                while(!index.empty() && height[i] <= height[index.top()]){
                    int h = height[index.top()];
                    index.pop();
                    
                    int idx = index.size() == 0?-1:index.top();
                    if(h*(i-idx-1) > ret){
                        ret = h*(i-idx-1);
                    }
                }
                index.push(i);
                
                
            }
            
            return ret;
        }
    };
