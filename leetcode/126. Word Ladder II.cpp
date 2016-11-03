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
    vector<string> path;
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> res;
    void findNext(string s, unordered_set<string>& wordList, unordered_set<string>& next){
        for(int i = 0; i < s.size(); i++){
            string c = s;
            for(int j = 0; j < 26; j++){
                c[i] = 'a'+ j;
                if(wordList.count(c)){
                    next.insert(c);
                    mp[c].push_back(s);
                }
            }
        }
    }
    void output(string& begin, string end){
        if(begin == end){
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }
        else{
            for(int i = 0; i < mp[end].size(); i++){
                path.push_back(mp[end][i]);
                output(begin,mp[end][i]);
                path.pop_back();
            }
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        wordList.insert(endWord);
        unordered_set<string> cur;
        cur.insert(beginWord);
        unordered_set<string> next;
        path.push_back(endWord);
        while(true){
            for(auto it:cur) wordList.erase(it);
            for(auto it:cur){
                findNext(it, wordList,next);
            }
            if(next.empty()) return res;
            if(next.count(endWord)){
                output(beginWord, endWord);
                return res;
            }
            cur = next;
            next.clear();
        }
        return res;


    }
};
