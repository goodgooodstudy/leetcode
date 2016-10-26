/**
* @Author: lcy
* @Date:   2016-10-26T16:32:19-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// 243. Shortest Word Distance   QuestionEditorial Solution  My Submissions
// Total Accepted: 19016
// Total Submissions: 38337
// Difficulty: Easy
// Contributors: Admin
// Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
//
// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.
//
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -1;
        int len = INT_MAX;
        for(int i = 0; i < words.size(); i++){
            if( (words[i] == word1 || words[i] == word2)){
                if(idx >=0 && words[i] != words[idx]){
                    len = min(i-idx, len);
                }
                idx =  i;
            }
        }
        return len;

    }
};
