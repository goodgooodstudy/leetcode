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



class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>>q;
        unordered_set<string> word_dict(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        vector<string> rst({beginWord});
        q.push(rst);
        bool found = false;
        vector<vector<string>> routes;
        while(!q.empty()){
            unordered_set<string> cur_visited;
            int n = q.size();
            while(n-- > 0){
                vector<string> cur = q.front();
                q.pop();
                string cur_word = cur.back();
                vector<string> next_words = findNext(cur_word, word_dict, visited);
                for(string s : next_words){
                    vector<string> n(cur);
                    n.push_back(s);
                    cur_visited.insert(s);
                    if(s == endWord) {
                        found = true;
                        routes.push_back(n);
                    }
                    q.push(n);
                } 
            }
            for(string c : cur_visited) visited.insert(c);
            if(found) return routes;
        }
        return routes;
        
        
    }
    vector<string> findNext(string word, unordered_set<string>& dict, unordered_set<string>& visited){
        vector<string> res;
        for(int i = 0; i < word.size(); i++){
            char ori = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(dict.count(word)&&!visited.count(word))
                res.push_back(word);
            }
            word[i] = ori;
        }
        return res;
    }
};
