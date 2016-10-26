/**
* @Author: lcy
* @Date:   2016-10-26T16:41:43-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



// 244. Shortest Word Distance II   QuestionEditorial Solution  My Submissions
// Total Accepted: 13423
// Total Submissions: 38487
// Difficulty: Medium
// Contributors: Admin
// This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
//
// Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
//
// For example,
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
//
// Given word1 = “coding”, word2 = “practice”, return 3.
// Given word1 = "makes", word2 = "coding", return 1.
//
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

// use hash table to keep where the target is.
// two sorted array find the minimal difference , can use two pointers a little like binary search
class WordDistance {
private:
    unordered_map<string, vector<int>> dict;
public:
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); i++){
            dict[words[i]].push_back(i);
        }

    }
    int shortest(string s1, string s2){
        vector<int> idx1 = dict[s1];
        vector<int> idx2 = dict[s2];
        int len = INT_MAX;
        int i1 = 0, i2 = 0;
        while(i1 < idx1.size() && i2 < idx2.size()){
            len = min(len, abs(idx2[i2] - idx1[i1]));
            if(idx1[i1] < idx2[i2]){
                i1++;
            }
            else{
                i2++;
            }
        }
        return len;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");
