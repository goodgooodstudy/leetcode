/**
* @Author: lcy
* @Date:   2016-10-27T15:23:58-04:00
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// 308. Range Sum Query 2D - Mutable   QuestionEditorial Solution  My Submissions
// Total Accepted: 7873
// Total Submissions: 39061
// Difficulty: Hard
// Contributors: Admin
// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//
// Range Sum Query 2D
// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//
// Example:
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
//
// sumRegion(2, 1, 4, 3) -> 8
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
// Note:
// The matrix is only modifiable by the update function.
// You may assume the number of calls to update and sumRegion function is distributed evenly.
// You may assume that row1 ≤ row2 and col1 ≤ col2.

// 2D BIT, each node on the sum matrix store j-j&(-j) -> j (ith row) and i-i&(-i)-i (j the col)
// add logilogj
// sum lognlogm


class NumMatrix {
private:
    vector<vector<int>> BIT;
    vector<vector<int>> nums;
    int m;
    int n;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if(matrix.size() == 0|| matrix[0].size() == 0) return;
        m = matrix.size();
        n = matrix[0].size();
        nums = matrix;
        BIT = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                add(i, j, matrix[i][j]);
            }
        }

    }
    void add(int i, int j, int val){
        i++;
        j++;
        while(i <= m){
            int col = j;
            while(col <= n){
                BIT[i][col] += val;
                col += col&(-col);
            }
            i += i&(-i);
        }
    }
    int getSum(int row, int col){
        row++;
        col++;
        int sum = 0;
        while(row > 0){
            int j = col;
            while(j > 0){
                sum += BIT[row][j];
                j -= j&(-j);
            }
            row -= row&(-row);
        }
        return sum;
    }
    void update(int row, int col, int val) {
        int change = val- nums[row][col];
        if(change!=0){
            add(row, col, change);
            nums[row][col] = val;
        }


    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = getSum(row2, col2);
        int sumS=0;
        if(row1 > 0 && col1 > 0 ) sumS = getSum(row1-1, col1-1);
        int sumL = 0, sumU = 0;
        if(col1 > 0) sumL = getSum(row2, col1-1);
        if(row1 > 0) sumU = getSum(row1-1, col2);
        return sum - sumL -sumU + sumS;


    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
