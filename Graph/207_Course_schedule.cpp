//https://leetcode.com/problems/course-schedule/
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//O(n+p)

class Solution {
public:
    //cource -> prerq map
    unordered_map<int, vector<int>> mp;
    unordered_set<int> visited;

    bool dfs(int course){
        cout<<"course :" << course<<endl;
        //check if we already visited the course. loop check
        if(visited.find(course) != visited.end()){
            return false;
        }

        //check if the current dose not have any more prereq to vist
        if(mp[course].size() == 0){
            return true;
        }

        //now the course to visit
        visited.insert(course);

        //check if it has prerqs
        for(auto cr: mp[course]){
            //the prereq is already visited then there is a intedependancy
            if(!dfs(cr)){return false;}
        }

        //so now we are done with the validation with the current course, we can clean the visisted list and from course map as wekk
        visited.erase(course);
        mp[course] = {};
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Create the course->prereq map
        for (auto course :prerequisites){
            mp[course[0]].push_back(course[1]);
        }

        //we need to validate for the each set of course for this
        for(int cr = 0;cr < numCourses; cr++){
            if(!dfs(cr)){ return false;}
        }
        return true;
    }
};

int main(){
    Solution s;
    bool ans;
    vector<vector<int > > a;//{ {1,0}, {0,1} };
    a.push_back({1,0});
    a.push_back({0,1});
    cout<<"Prereq vector"<<endl;
    for(auto aa:a){
        for(auto aaa :aa){
            cout << aaa<<"\t";
        }
        cout << endl;
    }

    ans = s.canFinish(2, a);
    cout << "Answer : "<<ans<<endl;
    Solution s1;
    vector<vector<int > > b;//{ {1,0}, {0,1} };
    b.push_back({0,1});
    b.push_back({0,2});
    b.push_back({1,3});
    b.push_back({1,4});
    b.push_back({3,4});
    cout<<"Prereq vector"<<endl;
    for(auto aa:b){
        for(auto aaa :aa){
            cout << aaa<<"\t";
        }
        cout << endl;
    }
    //a.push_back({0,1});
    bool ans1 = s1.canFinish(5, b);
    cout << "Answer : "<<ans1<<endl;

    bool ans2;
    Solution s2;
    vector<vector<int > > c;//{ {1,0}, {0,1} };
    c.push_back({1,0});
    cout<<"Prereq vector"<<endl;

    for(auto aa:c){
        for(auto aaa :aa){
            cout << aaa<<"\t";
        }
        cout << endl;
    }
    ans2 = s2.canFinish(2, c);
    cout << "Answer : "<<ans2<<endl;
    return 0;
}
