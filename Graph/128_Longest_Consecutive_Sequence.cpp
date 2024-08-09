//https://leetcode.com/problems/longest-consecutive-sequence/description/
/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109

*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
        When we choose the Brute Force methos it will be O(N3).
        As we have to pick one number and then pick each sequence number and search in the entier array.

        Option 2: we can sort the array and check the sequence in loop so effective it will be o(nlogn)

        Option 3: Hash with integillent sequence check
        Here we add all the given number in the unordered_set that is hash unordered_set.
        For each number we pick if we have the previous number in the hash then it must be accounted before so skip this.

        IF we don't find in the hash then It can considered as the starting point of chain of number.
        Each time we start looking for the next number we can keep incrementing the count.

        At the end of the each positive pick we will compare with the existing MAX and update.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_num =1;
        if(nums.size() == 0){ return 0;}

        unordered_set<int> hash_list;
        for(auto n: nums){
            hash_list.insert(n);
        }

        for(int i =0; i<nums.size(); i++){
            int count = 1;

            int prev = nums[i]-1;
            int next = nums[i]+1;
            if(hash_list.find(prev) != hash_list.end()){
                continue;
            }
             while(hash_list.find(next) != hash_list.end()){
                count +=1;
                next +=1;
             }
             max_num = max(max_num,count);
        }
        return max_num;
    }
};