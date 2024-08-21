//https://leetcode.com/problems/rotate-image/
/*You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
Example 2:


Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 20
-1000 <= matrix[i][j] <= 1000
*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int l = 0;
        int r = matrix.size() -1;
        while(l<r){
            for(int i = 0; i <(r-l); ++i){
                int top = l;
                int bottom = r;
                int topleft = matrix[top][l+i];

                //move bottom left -> top left
                matrix[top][l+i] = matrix[bottom-i][l];
                //bootom right -> bottom left
                matrix[bottom-i][l] = matrix[bottom][r -i];
                //top right -> bottom right
                matrix[bottom][r-i] = matrix[top+i][r];
                //top left -> top right
                matrix[top+i][r] = topleft;

            }
            l++;
            r--;
        }
    }
};