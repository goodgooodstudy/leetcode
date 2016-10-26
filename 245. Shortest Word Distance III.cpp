/**
* @Author: lcy
* @Date:   2016-10-26T16:44:40-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



// 245. Shortest Word Distance III   QuestionEditorial Solution  My Submissions
// Total Accepted: 12686
// Total Submissions: 26177
// Difficulty: Medium
// Contributors: Admin
// This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
//
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
// word1 and word2 may be the same and they represent two individual words in the list.
//
// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
// Given word1 = “makes”, word2 = “coding”, return 1.
// Given word1 = "makes", word2 = "makes", return 3.
//
// Note:
// You may assume word1 and word2 are both in the list.

// just list when word1 == word2 and min(len, curdiff)..........

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int idx = -1;
        int len = INT_MAX;
        for(int i = 0; i < words.size(); i++){
            if(words[i] == word1 || words[i] == word2){
                if(idx >= 0 && (word1 == word2 || words[idx]!=words[i]) ){
                    len = min(len, i-idx);
                }
                idx = i;
            }
        }
        return len;
    }
};
