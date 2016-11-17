/**
* @Author: lcy
* @Date:   2016-09-10T04:18:31-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, multiset<string>> m;
        vector<vector<string>> res;
        for(auto a : strings){
            string tmp="";
            for(char t : a){
                tmp += to_string((t+26-a[0])%26)+",";
            }
            m[tmp].insert(a);
        }
        for(auto p : m){
            res.push_back(vector<string>(p.second.begin(),p.second.end()));
        }
        return res;

    }
};

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> rst;
        for(int i = 0; i <strings.size(); i++){
            string cur = strings[i];
            string key;
            for(int i = 0; i < cur.size(); i++){
                key+=to_string( (cur[i]-cur[0]+26)%26 )+",";
            }
            dict[key].push_back(strings[i]);
        }
        for(auto p:dict){
            rst.push_back(p.second);
        }
        return rst;
    }
};
