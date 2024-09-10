//https://leetcode.com/problems/course-schedule-ii/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool dfs(int course,vector<vector<int> >& adjList,vector<int>& s,vector<int>& visited){
        //setting to visiting
        visited[course] = 1;

        //getting all the prereq for this given coures
        for(int v: adjList[course]){
            //if the course is already visiting then a cycle
            if(visited[v] == 1){return true;}

            if(visited[v] == 0 and dfs(v,adjList,s,visited)){ return true;}
        }

        //when all the add list complete then mark the course complete
        visited[course] = 2;
        s.push_back(course);

        //default: we did not find any cycle
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites) {
        //create a adjacency list
        vector<vector<int> > adjList(numCourses);
        for(auto course:prerequisites){
            adjList[course[1]].push_back(course[0]);
        }
        //create a stack with state [0:unvisted, 1:visiting,2:visted]
        vector<int> s;

        vector<int> visited(numCourses,0);

        //now check all the courses
        for(int i =0; i< numCourses;i++){
            if(visited[i] == 0 and dfs(i,adjList,s,visited)){ return {};}
        }

        reverse(s.begin(),s.end());
        return s;
    }
};
