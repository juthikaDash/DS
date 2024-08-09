//https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/description/
/*
You have a graph of n nodes. You are given an integer n and an array edges where edges[i] = [ai, bi] indicates that there is an edge between ai and bi in the graph.

Return the number of connected components in the graph.

 

Example 1:


Input: n = 5, edges = [[0,1],[1,2],[3,4]]
Output: 2
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[3,4]]
Output: 1
 

Constraints:

1 <= n <= 2000
1 <= edges.length <= 5000
edges[i].length == 2
0 <= ai <= bi < n
ai != bi
There are no repeated edges.
*/
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    void dfs(vector<int> adjList[],vector<int>  &visited, int src){
        visited[src] = 1;

        //for the given node we need to traverse all the adjacent nodes, 
        //if it is not visited before
        auto adj_list = adjList[src];
        for(int i = 0; i<adj_list.size();i++){
            if(visited[adj_list[i]] == 0){
                dfs(adjList, visited, adj_list[i]);
            }
        }
    }

    int countComponents(int n, vector<vector<int> >& edges) {
        if(n == 0){ return 0;}

        vector<int> visited(n,0);
        vector<int> adjList[n];

        int component = 0;

        //create the adjList from edges
        for(int i = 0; i<edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);

        }

        //checking the component calling the dfs call for visiting adjList nodes
        for(int i = 0; i< n; i++){
            if(visited[i] == 0){
                dfs(adjList, visited, i);
                component++;
            }
        }

        return component;

    }
};