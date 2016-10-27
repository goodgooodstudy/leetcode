/**
* @Author: lcy
* @Date:   2016-10-27T00:24:29-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;



// 311. Sparse Matrix Multiplication   QuestionEditorial Solution  My Submissions
// Total Accepted: 13291
// Total Submissions: 26830
// Difficulty: Medium
// Contributors: Admin
// Given two sparse matrices A and B, return the result of AB.
//
// You may assume that A's column number is equal to B's row number.
//
// Example:
//
// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]
//
// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]
//
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
// Show Company Tags
// Show Tags

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size();
        int n = B[0].size();
        vector<vector<int>> rst(m, vector<int>(n, 0));
        vector<vector<int>> A_non_zero(m, vector<int>());
        vector<vector<int>> B_non_zero(n, vector<int>());
        for(int i = 0; i < m; i++){
            for(int j = 0; j < A[0].size(); j++){
                if(A[i][j])A_non_zero[i].push_back(j);
            }
        }
        for(int i = 0; i < B.size(); i++){
            for(int j = 0; j < n; j++){
                if(B[i][j])B_non_zero[j].push_back(i);
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int idx1 = 0, idx2 = 0;
                while(idx1 < A_non_zero[i].size() && idx2 < B_non_zero[j].size()){
                    if(A_non_zero[i][idx1] == B_non_zero[j][idx2]){
                        rst[i][j] += A[i][A_non_zero[i][idx1]]*B[B_non_zero[j][idx2]][j];
                        idx1++;
                        idx2++;
                    }
                    else if(A_non_zero[i][idx1] < B_non_zero[j][idx2]){
                        idx1++;
                    }
                    else{
                        idx2++;
                    }
                }
            }
        }
        return rst;
    }
};
