/**
* @Author: lcy
* @Date:   2016-10-31T20:39:03-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 438. Find All Anagrams in a String   QuestionEditorial Solution  My Submissions
// Total Accepted: 3938
// Total Submissions: 11820
// Difficulty: Easy
// Contributors: Stomach_ache
// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
//
// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
//
// The order of output does not matter.
//
// Example 1:
//
// Input:
// s: "cbaebabacd" p: "abc"
//
// Output:
// [0, 6]
//
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:
//
// Input:
// s: "abab" p: "ab"
//
// Output:
// [0, 1, 2]
//
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        string target(p);
        vector<int> sh(256,0), ph(256,0);
        vector<int> rst;
        if(s.size() < p.size()){
            return rst;
        }
        for(int i = 0; i < p.size(); i++){
            sh[s[i]]++;
            ph[p[i]]++;
        }
        if(sh == ph) rst.push_back(0);
        for(int i = p.size(); i < s.size(); i++){
            sh[s[i]]++;
            sh[s[i-p.size()]]--;
            if(sh == ph) rst.push_back(i-p.size()+1);
        }
        return rst;
    }
};
