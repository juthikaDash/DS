//https://leetcode.com/problems/word-search/
/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board?


*/
#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        for (int i = 0; i< board.size(); ++i){
            for(int j =0;i<board[i].size(); ++j){
                if(board[i][j] == word[0] and dfs(board,word,  i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> >& board, string word, int i, int j, int cnt){
        if(cnt == word.size()){
            return true;
        }
        //check the boudary , mo need to continue
        if(i <0 || i > board.size() || j <0 || j > board[i].size()){
            return false;
        }
       //found a mismatch then no need to continue the search
       if(board[i][j] != word[cnt]){
        return false;
       }
       //preserve the char and keep searching for all the directions
       auto ch = board[i][j];

       //remove the char from the current search path to avoid duplicate
       board[i][j] = ' ';

       bool found = (dfs(board,word, i+1,j , cnt+1) ||
                     dfs(board,word, i-1,j , cnt+1) ||
                     dfs(board,word, i,j+1 , cnt+1) ||
                     dfs(board,word, i,j-1 , cnt+1)
                     );

        //putting back the char for the future search
        board[i][j] = ch;

        return found;

    }
};