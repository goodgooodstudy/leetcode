/**
* @Author: lcy
* @Date:   2016-10-24T09:56:37-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> rst;
        for(int i = 0, k, l; i < words.size(); i = i + k){
            for(k =0, l = 0; i+k < words.size() && l + words[i+k].size() <= maxWidth-k; k++){
                l = l+ words[i+k].size();
            }
            string tmp = words[i];
            for(int j = 1; j < k; j++){
                if(i+k == words.size()) tmp += " ";
                else tmp += string((maxWidth-l)/(k-1) + (j <= (maxWidth-l)%(k-1)),' '); //k-1!!!!
                tmp += words[i+j];
            }
            tmp += string(maxWidth-tmp.size(),' ');
            rst.push_back(tmp);
        }
        return rst;

    }
};
