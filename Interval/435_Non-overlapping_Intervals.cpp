//https://leetcode.com/problems/non-overlapping-intervals/description/
/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

Constraints:

1 <= intervals.length <= 105
intervals[i].length == 2
-5 * 104 <= starti < endi <= 5 * 104
*/
class Solution {
    /*
    This problem can be solved in Brute Force, DP and Greedy Apporach,
    The best way is Greedy as it will take o(nlon) of runtime complexity and O(1) as space complexity.

    - We first sort the array with reference to the start time (common across all the methods)
    - we can track if the next meeting is start point is before the end point of the current one.
    - If it is YES then increment the "interval_removed" and check which has early end point.
    - We always track the early close point so that it will better performance and proability of the clashing is less.

    [[1,2],[2,3],[3,4],[1,3]]
    [[1,2],[1,3],[2,3],[3,4]]
*/
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

public:
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if(intervals.size() == 0){return 0;}

        //Sort the given interval
        sort(intervals.begin(), intervals.end());

        //prev interval end value to compare the onverlap
        int prev_end = intervals[0][1];
        
        int interval_removed = 0;

        for(int i =1; i< intervals.size(); i++){
            //no overlap then update the prev_interval end
            if(intervals[i][0] >= prev_end){
                prev_end = intervals[i][1];
            }
            //overlap then increment the result and update prev_end
            else{
                interval_removed +=1;
                prev_end = min(intervals[i][1],prev_end );
            }
        }

        return interval_removed;
    }
};