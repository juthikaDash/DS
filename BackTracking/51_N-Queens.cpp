//https://leetcode.com/problems/n-queens/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        //vector to store res;
        vector<vector<string> > res;

        //current postion of the queen
        vector<pair<int,int> > point;

        //call the solve
        solveNQ(res,point,n,0);
        return res;
    }

    void solveNQ(vector<vector<string> > &res,vector<pair<int,int> > &point, int n, int row ){
        //base condition
        if(row == n){
            //initiliaze the board of chase line
            string chess_line(n,'.');

            vector<string> sol (n, chess_line);

            //fill the solution
            for(int i =0; i<point.size();i++){
                sol[point[i].first][point[i].second] = 'Q';
            }
            res.push_back(sol);
        }

        //search each possible pos
        for(int col = 0; col <n;col++){
            pair<int,int> new_position = make_pair(row,col);

            if(is_safe(point, new_position)){
                point.push_back(new_position);
                solveNQ(res, point, n,row+1);
                point.pop_back();
            }
        }
    }
    bool is_safe(vector<pair<int,int> > &point, pair<int,int>& position){
       //Check if this position is not under attack from a previous queen
        /*
             Note: A queen be get attacked by another queen if we place
                1. In the same row (row number is same)
                2. In the same col (col number is same)
                3. Diagonally top left to down (where row - col will be same)
                4. Diagonally botton left to top (where row + col will be same)
                
                If any of the above is happening then the queen will be get attacked otherwise not.
                So when we find a safe place then we will addthe position to the position array.
            */

           for(int i =0; i<point.size();i++){
            if((position.first == point[i].first) || //same row
            (position.second == point[i].second)  || //same col
            ( point[i].first - point[i].second) == (position.first - position.second) || //positive diagonal
            ( point[i].first + point[i].second) == (position.first + position.second) //negative diagonal
            ){
                return false;
            }
           } 
           return true;
    }
};