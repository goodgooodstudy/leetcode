/**
* @Author: lcy
* @Date:   2016-11-03T20:14:07-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 424. Longest Repeating Character Replacement   QuestionEditorial Solution  My Submissions
// Total Accepted: 2848
// Total Submissions: 7469
// Difficulty: Medium
// Contributors: Admin
// Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
//
// Note:
// Both the string's length and k will not exceed 104.
//
// Example 1:
//
// Input:
// s = "ABAB", k = 2
//
// Output:
// 4
//
// Explanation:
// Replace the two 'A's with two 'B's or vice versa.
// Example 2:
//
// Input:
// s = "AABABBA", k = 1
//
// Output:
// 4
//
// Explanation:
// Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.
// Show Company Tags
// Show Similar Problems

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = -1;
        unordered_map<char, int> dict; // vector<int> dict(26,0)
        int mx = 0;
        int mxCharcnt = 0;
        for(int j = 0; j < s.size(); j++){
            dict[s[j]]++;
            if(dict[s[j]] > mxCharcnt){
                mxCharcnt = dict[s[j]];
            }
            while(j-i - mxCharcnt > k){
                dict[s[++i]]--;
                for(auto p : dict){
                    mxCharcnt = max(mxCharcnt, p.second);
                }
            }
            mx = max(mx, j-i);
        }
        return mx;
    }
};
