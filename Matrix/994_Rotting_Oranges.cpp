//https://leetcode.com/problems/rotting-oranges/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Dfs
class Solution {
public:
    int n,m;
    void fun(vector<vector<int> >& grid, int i , int j, int time){
        if(i<0 || i==n || j<0 || j==m || grid[i][j]==0 || (grid[i][j]<time && grid[i][j]>1)){
            return ;
        }
        grid[i][j] = time;
        fun(grid,i-1,j,time+1);
        fun(grid,i,j-1,time+1);
        fun(grid,i+1,j,time+1);
        fun(grid,i,j+1,time+1);
    }

    int orangesRotting(vector<vector<int> >& grid) {
        n =grid.size();
        m =grid[0].size();
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    fun(grid,i,j,2);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
                ans= max(ans,grid[i][j]);
            }
        }
        return ans-2;
    }
};
//bfs
class Solution1{
public:

    int n,m;
    queue<vector<int> > q;
    void fun(vector<vector<int> >& grid) {
        while (!q.empty()) {
            vector<int> v = q.front();
            q.pop();

            int i = v[0], j = v[1], t = v[2];

            if (i - 1 >= 0 && (grid[i - 1][j] == 1 || grid[i - 1][j] > t + 1)) {
                grid[i - 1][j] = t + 1;
                q.push({i - 1, j, t + 1});
            }
            if (j - 1 >= 0 && (grid[i][j - 1] == 1 || grid[i][j - 1] > t + 1)) {
                grid[i][j - 1] = t + 1;
                q.push({i, j - 1, t + 1});
            }
            if (i + 1 < n && (grid[i + 1][j] == 1 || grid[i + 1][j] > t + 1)) {
                grid[i + 1][j] = t + 1;
                q.push({i + 1, j, t + 1});
            }
            if (j + 1 < m && (grid[i][j + 1] == 1 || grid[i][j + 1] > t + 1)) {
                grid[i][j + 1] = t + 1;
                q.push({i, j + 1, t + 1});
            }
        }
    }

    int orangesRotting(vector<vector<int> >& grid) {
        n =grid.size();
        m =grid[0].size();
        int ans=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,2});
                    fun(grid);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
                ans= max(ans,grid[i][j]);
            }
        }
        return ans-2;
    }
};
