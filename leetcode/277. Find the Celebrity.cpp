/**
* @Author: lcy
* @Date:   2016-10-27T09:20:58-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 277. Find the Celebrity   QuestionEditorial Solution  My Submissions
// Total Accepted: 14957
// Total Submissions: 42157
// Difficulty: Medium
// Contributors: Admin
// Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.
//
// Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).
//
// You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.
//
// Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.

// Forward declaration of the knows API.

// very concise。。。。
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        //find the candidate(only one, if i knows candidate, i is not, if i does not know candidate, candidate is not.. all the person has been considered)
        for(int i = 1; i < n; i++){
            if(!knows(i, candidate)) candidate = i;
        }
        //check the candidate
        for(int i = 0; i < n; i++){
            if(i == candidate) continue;
            if(!knows(i, candidate) || (knows(candidate,i))) return -1;
        }
        return candidate;
    }
};
