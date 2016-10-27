/**
* @Author: lcy
* @Date:   2016-10-26T17:12:14-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 170. Two Sum III - Data structure design   QuestionEditorial Solution  My Submissions
// Total Accepted: 18245
// Total Submissions: 80741
// Difficulty: Easy
// Contributors: Admin
// Design and implement a TwoSum class. It should support the following operations: add and find.
//
// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the value.
//
// For example,
// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false

class TwoSum {
private:
    unordered_map<int, int> maps;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    maps[number]++;

	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto& p : maps){
	        int v = p.first;
	        p.second --;
	        if(maps.count(value-v) && maps[value-v] >0){
	            p.second++;
	            return true;
	        }
	        p.second++;
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
