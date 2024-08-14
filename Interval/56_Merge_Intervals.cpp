//https://leetcode.com/problems/merge-intervals/description/
/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > merge(vector<vector<int> >& intervals) {
        vector<vector<int> > result;
        if(intervals.size() == 0){
            return result;
        }

        //sort the intervals list by using the first parameter
        sort(intervals.begin(), intervals.end());

        result.push_back(intervals[0]);

        for(int i = 1; i< intervals.size(); i++){
            auto prev_interval = result.back();
            if(intervals[i][0] <= prev_interval[1]){
                auto merged_interval = {min(intervals[i][0], prev_interval[0]), 
                                        max(intervals[i][1],prev_interval[1] )};
                result.pop_back();
                result.push_back(merged_interval);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};