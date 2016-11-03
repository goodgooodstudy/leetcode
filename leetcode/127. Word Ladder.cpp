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

// 127. Word Ladder   QuestionEditorial Solution  My Submissions
// Total Accepted: 97497
// Total Submissions: 504349
// Difficulty: Medium
// Contributors: Admin
// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
// Only one letter can be changed at a time
// Each intermediate word must exist in the word list
// For example,
//
// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
//
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord,1));
        while(!q.empty()){
            string s = q.front().first;
            int len = q.front().second;
            if(s == endWord) return len;
            q.pop();
            vector<string> neighbors = findNeighbors(s, wordList);
            for(int i = 0; i < neighbors.size();i++){
                q.push(make_pair(neighbors[i],len+1));
            }
        }
        return 0;
    }

    vector<string> findNeighbors(string s, unordered_set<string>& wordList){
        vector<string> rst;
        for(int i =0; i<s.size();i++){
            char c = s[i];
            for(int j = 0; j<26;j++){
                if(c == 'a'+j) continue;
                s[i] = 'a'+j;
                if(wordList.count(s)){
                    rst.push_back(s);
                    wordList.erase(s);
                }
            }
            s[i] = c;
        }
        return rst;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.erase(beginWord);
        wordList.erase(endWord);
        unordered_set<string> begins;
        unordered_set<string> ends;
        begins.insert(beginWord);
        ends.insert(endWord);
        int ladder = 2, len = beginWord.size();
        while(!begins.empty() && !ends.empty()){
            if(begins.size() > ends.size()){
                swap(begins, ends);
            }
            unordered_set<string> tmp;
            for(string s : begins){
                for(int i = 0; i < len; i++){
                    char c = s[i];
                    for(int k = 0; k < 26; k++){
                        s[i] = 'a' + k;
                        if(s[i] == c) continue;
                        if(ends.count(s)){
                            return ladder;
                        }
                        if(wordList.count(s)){
                            tmp.insert(s);
                            wordList.erase(s);
                        }
                    }
                    s[i] = c;
                }
            }
            ladder++;
            swap(begins, tmp);
        }
        return 0;

    }

};
