class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res(nums.size(),0);
        int i = a >= 0? nums.size()-1: 0;
        int start = 0, end = nums.size()-1;
        while(start <= end){
            int startNum = getNum(nums[start],a,b,c);
            int endNum = getNum(nums[end],a,b,c);
            if(a >= 0){
                if(startNum > endNum){
                    res[i--] = startNum;
                    start++;
                }
                else{
                    res[i--] = endNum;
                    end--;
                }
            }
            else{
                if(startNum > endNum){
                    res[i++] = endNum;
                    end--;
                }
                else{
                    res[i++] = startNum;
                    start++;
                }
            }
        }
        return res;
        
    }
    
    int getNum(int num, int a, int b, int c){
        return a*num*num + b*num + c;
    }
    
};
