/**
* @Author: lcy
* @Date:   2016-10-27T09:47:42-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



// 340. Longest Substring with At Most K Distinct Characters   QuestionEditorial Solution  My Submissions
// Total Accepted: 9802
// Total Submissions: 25043
// Difficulty: Hard
// Contributors: Admin
// Given a string, find the length of the longest substring T that contains at most k distinct characters.
//
// For example, Given s = “eceba” and k = 2,
//
// T is "ece" which its length is 3.

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> mp;
        int i = -1;
        int cnt = 0;
        int len = 0;
        for(int j = 0; j < s.size(); j++){
            if(!mp.count(s[j]) || mp[s[j]] <= i){
                cnt++;
            }
            mp[s[j]] = j;
            while(cnt > k){
                if(mp[s[++i]] == i) cnt--;
            }
            len = max(j-i, len);

        }
        return len;

    }
};
