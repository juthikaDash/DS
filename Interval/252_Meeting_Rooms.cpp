//https://leetcode.com/problems/meeting-rooms/description/
/*Topics
Companies
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
/*
    It is best to first sort the array, so that we just need to 
    compare the 2nd element start point with previous element end point.
*/
    bool canAttendMeetings(vector<vector<int> >& intervals) {

        if(intervals.size() == 0){ return true;}

        sort(intervals.begin(), intervals.end());

        for(int i =1; i < intervals.size(); i++){
            if(intervals[i][0] < intervals[i-1][1]){
                return false;
            }
        }
        return true;
    }
};