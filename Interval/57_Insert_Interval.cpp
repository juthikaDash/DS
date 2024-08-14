//https://leetcode.com/problems/insert-interval/description/
/*
You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

 

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

*/
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) {
        vector<vector<int> > result;
        for(int i = 0; i< intervals.size(); i++){
            //beginning of the interval
            if(newInterval[1]< intervals[i][0]){
                result.push_back(newInterval);
                for(int j = i; j< intervals.size();j++){
                    result.push_back(intervals[j]);
                }
                 return result;
            }
            //new interval after the current
            else if( intervals[i][1]< newInterval[0]){
                result.push_back(intervals[i]);
            }
            //if still checking means there is a overlap
            else{
                newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            }
        }
        //at the end of the loop if it is still processing means the newInterval will be added at the end
        result.push_back(newInterval);
        return result;
    }
};