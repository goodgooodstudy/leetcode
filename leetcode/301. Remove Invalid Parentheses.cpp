/**
* @Author: lcy
* @Date:   2016-09-03T12:50:54-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') left++;
            if(s[i] == ')'){
                if(left > 0) left--;
                else right++;
            }
        }
        unordered_set<string> rst;
        removehelper(s, 0, "", left, right, 0, rst);
        return vector<string>(rst.begin(), rst.end());

    }

    void removehelper(string s, int idx, string cur, int remove_left, int remove_right, int pair, unordered_set<string>& rst){
        if(idx == s.size()){
            if(remove_left == 0 && remove_right == 0 && pair == 0){
                rst.insert(cur);
            }
            return;
        }
            if(s[idx] == '('){
                if(remove_left >0){
                    removehelper(s, idx+1, cur,remove_left-1, remove_right, pair, rst);
                }
                removehelper(s, idx+1, cur+"(", remove_left, remove_right, pair+1, rst);
            }
            else if(s[idx] == ')'){
                if(remove_right > 0){
                    removehelper(s, idx+1, cur, remove_left, remove_right-1, pair, rst);
                }
                if(pair>0){
                    removehelper(s, idx+1, cur+")", remove_left, remove_right, pair-1, rst);
                }
            }
            else{
                removehelper(s, idx+1, cur+s[idx], remove_left, remove_right, pair, rst);
            }

    }
};
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> visited;
        queue<string> q;
        vector<string> res;
        bool found = false;

        q.push(s);
        visited.insert(s);
        while(!q.empty()){
            string cur = q.front();
            q.pop();
            if(isValid(cur)){
                res.push_back(cur);
                found = true;
            }
            else if(found == false){
                for(int i = 0; i < cur.size(); i++){
                    // string tmp = cur.substr(0,i) + cur.substr(i+1);
                    if(cur[i] == '(' || cur[i] == ')'){
                        string tmp = cur.substr(0,i) + cur.substr(i+1);
                        if(!visited.count(tmp)){
                            q.push(tmp);
                            visited.insert(tmp);
                        }
                    }
                }
            }
        }
        return res;


    }
    bool isValid(string s){
        int cnt = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') cnt++;
            if(s[i] == ')'){
                if(cnt == 0) return false;
                cnt--;
            }
        }
        return cnt == 0;
    }
};
