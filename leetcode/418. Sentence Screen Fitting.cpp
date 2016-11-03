/**
* @Author: lcy
* @Date:   2016-10-30T11:39:01-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 418. Sentence Screen Fitting   QuestionEditorial Solution  My Submissions
// Total Accepted: 2108
// Total Submissions: 8468
// Difficulty: Medium
// Contributors: Admin
// Given a rows x cols screen and a sentence represented by a list of words, find how many times the given sentence can be fitted on the screen.
//
// Note:
//
// A word cannot be split into two lines.
// The order of words in the sentence must remain unchanged.
// Two consecutive words in a line must be separated by a single space.
// Total words in the sentence won't exceed 100.
// Length of each word won't exceed 10.
// 1 ≤ rows, cols ≤ 20,000.
// Example 1:
//
// Input:
// rows = 2, cols = 8, sentence = ["hello", "world"]
//
// Output:
// 1
//
// Explanation:
// hello---
// world---
//
// The character '-' signifies an empty space on the screen.
// Example 2:
//
// Input:
// rows = 3, cols = 6, sentence = ["a", "bcd", "e"]
//
// Output:
// 2
//
// Explanation:
// a-bcd-
// e-a---
// bcd-e-
//
// The character '-' signifies an empty space on the screen.
// Example 3:
//
// Input:
// rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]
//
// Output:
// 1
//
// Explanation:
// I-had
// apple
// pie-I
// had--
//
// The character '-' signifies an empty space on the screen.


class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int all = 0;
        for(string s : sentence) all+=s.size()+1;
        int cnt = 0;
        int idx = 0;

        for(int i = 0; i < rows; i++){
            int len = cols+1;
            cnt += len / all;
            len = len % all;
            while(len - (int)sentence[idx].size()-1>=0){ //!!!!(int)
                len -= sentence[idx].size()+1;
                idx++;
                if(idx == sentence.size()){
                    cnt++;
                    idx = 0;
                }
            }
        }
        return cnt;

    }
};
