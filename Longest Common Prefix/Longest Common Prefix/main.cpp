//
//  main.cpp
//  Longest Common Prefix
//
//  Created by LiuChengyang on 23/1/16.
//  Copyright © 2016 LiuChengyang. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        for (auto str:strs){
            int len = 0;
            for (int i = 0; i<res.length() && i< str.size(); i++) {
                if (res[i] == str[i]) len++;
                else break;
            }
            res = res.substr(0,len);

        }
        return res;
        
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<string> t;
    cout <<t.empty()<<endl;
    t.push_back("a");
    t.push_back("b");
//    t.push_back("");
    Solution* tmp = new Solution();
    cout << tmp->longestCommonPrefix(t)<<endl;
    return 0;
}
