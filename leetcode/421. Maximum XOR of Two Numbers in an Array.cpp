/**
* @Author: lcy
* @Date:   2016-10-31T17:00:30-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.
//
// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.
//
// Could you do this in O(n) runtime?
//
// Example:
//
// Input: [3, 10, 5, 25, 2, 8]
//
// Output: 28
//
// Explanation: The maximum result is 5 ^ 25 = 28.


class trie{
public:
    vector<trie*> next;
    trie():next(2, nullptr){}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        trie* root = new trie();
        for(int n : nums){
            trie* cur = root;
            for(int i = 31; i >= 0; i--){
                int curBit = (n >> i)&1;
                if(cur->next[curBit] ==nullptr){
                    cur->next[curBit] = new trie();
                }
                cur = cur->next[curBit];
            }
        }

        int mx = 0;
        for(int n : nums){
            int curxor = 0;
            trie* cur = root;
            for(int i = 31; i >= 0; i--){
                int curBit = (n >> i)&1;
                if(cur->next[curBit^1]){
                    curxor += 1 << i;
                    cur = cur->next[curBit^1];
                }
                else{
                    cur = cur->next[curBit];
                }
            }
            mx = max(curxor, mx);
        }
        return mx;
    }
};
