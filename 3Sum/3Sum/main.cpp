//
//  main.cpp
//  3Sum
//
//  Created by LiuChengyang on 25/1/16.
//  Copyright © 2016 LiuChengyang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
//#include <distance>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());
        
        int total, gap;
        for(int i = 0; i<nums.size();i++){
            total = 0-nums[i];
            for(int j = i+1; j < nums.size()-2;j++){
                int k = nums.size()-1;
                while(j<k){
                    if(nums[j] + nums[k]< total){
                        j++;
                    }
                    else if(nums[j] + nums[k] > total){
                        k--;
                    }
                    else{
                        vector<int> tmp = {nums[i],nums[j],nums[k]};
                        results.push_back(tmp);
                        j++;
                        k--;
                        
                    }
                    
                }
            }
        }
        sort(results.begin(),results.end());
        
        auto l = unique(results.begin(), results.end());
        results.resize(distance(results.begin(), l));
         for (auto tmp:results){
             cout << tmp[0]<<" "<<tmp[1]<<" "<<tmp[2]<<endl;
        
         }
        
        return results;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int myints[] = {0,0,0,10,-10,20,-20};           // 10 20 20 20 30 30 20 20 10
    std::vector<int> myvector (myints,myints+7);
    Solution s;
    s.threeSum(myvector);
    return 0;
}
