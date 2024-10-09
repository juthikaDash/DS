#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int n = board.size();
        int m = board[0].size();
        if(n == 0 || m == 0){ return 0;}

        int i , j, left,top;
        int total = 0;

        for(i = 0; i<n;i++){
            top = i-1;
            for(j = 0; j<m ;j++){
                left = j-1;
                if((board[i][j] == 'X') && (left <0 || board[i][left] == '.' ) && (top <0 || board[top][j] == '.')){
                    total++;
                }
            }
        }

        return total;
    }
};
int main(){
    Solution s;
    vector<vector<char> > boards ;
    vector<char> b1;
    b1.push_back('X');
    b1.push_back('.');
    b1.push_back('.');
    b1.push_back('X');

    // = { 'X', '.', '.', 'X' };
    vector<char> b2;// = { ".", ".", ".", "X" };
    b2.push_back('.');
    b2.push_back('.');
    b2.push_back('.');
    b2.push_back('X');
    vector<char> b3;// = { ".", ".", ".", "X" }; 
    b3.push_back('.');
    b3.push_back('.');
    b3.push_back('.');
    b3.push_back('X');
    //board = { {"X",".",".","X"},{".",".",".","X"},{".",".",".","X"} } ;
    boards.push_back(b1);
    boards.push_back(b2);
    boards.push_back(b3);
    int bs = s.countBattleships(boards);
    cout<< "Total Battleship ="<<bs<<endl;
    return 0;
}