#include <bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;

// Function to add an edge to the adjacency list
void addEdge(vector<vector<char>> &adj, char s, char t){
    // Add edge from vertex s to t
    adj[s].push_back(t); 
    // Due to undirected Graph
    adj[t].push_back(s);
}

// Recursive function for DFS traversal
void DFSRec(vector<vector<char>> &adj, vector<bool> &visited, char s){
    // Mark the current vertex as visited
    visited[s] = true;

    // Print the current vertex
    cout << s << " ";

    // Recursively visit all adjacent vertices that are not visited yet
    for (char i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}

// Main DFS function that initializes the visited array
// and call DFSRec
void DFS(vector<vector<char>> &adj, char s){
    vector<bool> visited(adj.size(), false);
    // Call the recursive DFS function
    DFSRec(adj, visited, s);
}

int main(){
    int V = 5; // Number of vertices in the graph

    // Create an adjacency list for the graph
    vector<vector<char>> adj(V);

    // Define the edges of the graph
    vector<vector<char>> edges={{'s', 'r'},{'s', 'p'},{'r', 'p'},{'r', 'q'},{'r', 't'}};

    // Populate the adjacency list with edges
    for (auto &e : edges)
        addEdge(adj, e[0], e[1]);

    char source = 's'; // Starting vertex for DFS
    cout << "DFS from source: " << source << endl;
    DFS(adj, source); // Perform DFS starting from the source vertex

    return 0;
}