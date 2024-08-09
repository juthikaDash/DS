//https://leetcode.com/problems/graph-valid-tree/description/
/*
You have a graph of n nodes labeled from 0 to n - 1. You are given an integer n and a list of edges where edges[i] = [ai, bi] indicates that there is an undirected edge between nodes ai and bi in the graph.

Return true if the edges of the given graph make up a valid tree, and false otherwise.

 

Example 1:


Input: n = 5, edges = [[0,1],[0,2],[0,3],[1,4]]
Output: true
Example 2:


Input: n = 5, edges = [[0,1],[1,2],[2,3],[1,3],[1,4]]
Output: false
 

Constraints:

1 <= n <= 2000
0 <= edges.length <= 5000
edges[i].length == 2
0 <= ai, bi < n
ai != bi
There are no self-loops or repeated edges.

*/
/*
    Here two important treats of the tree we are validating.
    - There should not be any cycle beween the nodes
    - Tree should have all the node connect 

    Option -1
    Adjacency List + DFS
    - First create the adjacency list to know which node is connected which other node
    - then have visit list to track which are the node we visited already.

*/
#include<iostream>
#include<stdio.h>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    bool dfs( vector<int> adjList[],unordered_set<int> &visited,int src,int prev){
        //if current node is already visted then there is a loop, so return false
        if(visited.find(src) != visited.end()){
            return false;
        }
        visited.insert(src);

        for(int i =0; i<adjList[src].size(); i++){
            auto src_neigh = adjList[src][i];
            //if the node from where I come from then skip it
            if(src_neigh == prev){ continue;}

            //visit the adjList node
            if(!dfs(adjList,visited,src_neigh, src)){ return false;}
        }
        return true;
    }
    bool validTree(int n, vector<vector<int> >& edges) {
        //Empty graph is still a tree
        //We dont need this check as the contraint is "1 <= n <= 2000'
        if(n == 0){ return true;}

        unordered_set<int> visited;
        vector<int> adjList[n];

        //Create the adj list. As this is a undirected graph tehre will be 2 entries for both a->b and b->a
        for(int i = 0; i< edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);

        }

        //we will be using dfs to see all the nodes are visted and there is no cycle
        int prev = -1;
        if(!dfs(adjList,visited,0,-1)){
            return false;
        }

        if(n != visited.size()){
            return false;
        }

        return true;
    }
};