//https://leetcode.com/problems/spiral-matrix/description/
/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
/*
    move right: (row, col + 1)
    move downwards: (row + 1, col)
    move left: (row, col - 1)
    move upwards: (row - 1, col)


Algorithm

    Initialize the top, right, bottom, and left boundaries as up, right, down, and left.
    Initialize the output array result.
    Traverse the elements in spiral order and add each element to result:
        Traverse from left boundary to right boundary.
        Traverse from up boundary to down boundary.
        Before we traverse from right to left, we need to make sure that we are not on a row that has already been traversed. If we are not, then we can traverse from right to left.
        Similarly, before we traverse from top to bottom, we need to make sure that we are not on a column that has already been traversed. Then we can traverse from down to up.
        Remember to move the boundaries by updating left, right, up, and down accordingly.

*/ 
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if(matrix.size() == 0){ return res;}

        //calculate row and column
        int rows =  matrix.size();
        int cols = matrix[0].size();

        //set top, left, right, bottom
        int top = 0;
        int bottom = rows -1;
        int left = 0;
        int right = cols -1;
        while(res.size() < rows*cols){
            //travers left to right
            for(int i = left; i <= right; ++i){
                res.push_back(matrix[top][i]);
            }
            //change top
            ++top;

            //traverse top to down
            for(int i = top; i<=bottom; ++i){
                res.push_back(matrix[i][right]);
            }
            //change right
            --right;
            //traverse right to left
            if(top <= bottom){
                for(int i = right; i >= left; --i){
                    res.push_back(matrix[bottom][i]);
                }
            }
            //change bottom
            --bottom;
            //traverse down to top
            if(left <= right){
                for(int i = bottom; i>= top; --i){
                    res.push_back(matrix[i][left]);
                }
            }
            //change left
            ++left;
        }

        return res;

    }
};