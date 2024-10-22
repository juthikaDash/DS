//https://leetcode.com/problems/meeting-rooms-ii/description/
/*
Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int> >& intervals) {
        if(intervals.size() == 0){ return true;}
        vector<int>start_time;
        vector<int> end_time;

        for(auto meeting: intervals){
            start_time.push_back(meeting[0]);
            end_time.push_back(meeting[1]);
        }
        std::sort(start_time.begin(), start_time.end());
        std::sort(end_time.begin(), end_time.end());
        int room = 0;
        for (int i = 0,j=0; i<intervals.size();i++){
            if(start_time[i]<end_time[j]){
                rooms +=1;
            }
            else{
                
                ++j;
            }

        }
        return rooms;
    }
};