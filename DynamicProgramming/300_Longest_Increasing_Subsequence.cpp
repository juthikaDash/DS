//https://leetcode.com/problems/longest-increasing-subsequence/description/
/*
Option1[O(n2)]: We can use DP where we will create a DP of same size.
    Always keep track of the maximum length of the increasing subsequence.

    Pick up N+1th element in an array and check against 0th location to Nth location
    Each time we check if the checing position element is less than the current one then
    we need add that value at that location in the new array + 1. and so on.
    Finally we will arrive at the maximum length value.

    https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/LongestIncreasingSubsequence.java

    Option2[O(nlogn)]:
    Returns an iterator pointing to the first element in the range [first,last) which does not compare less than val.
    We can use lower_bound <- This will give the value just more than the comparision.
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4

    new_nums = []
    then add the first element from the nums
    new_nums = [10]

    When we itertate over the nums list we will pick one element and do a upper bound check with new_nums array.
    for(9,2,5,3,7,101,18){
        new_nums = [10]
    }

    This will get populated as below.
    [10] CHECK [9,2,5,3,7,101,18]
    [9]  CHECK [2,5,3,7,101,18]
    [2]  CHECK [5,3,7,101,18]
    [2, 5]  CHECK [3,7,101,18]
    [2, 3]  CHECK [7,101,18]
    [2, 3, 7]  CHECK [101,18]
    [2, 3, 7, 101]  CHECK [18]
    [2, 3, 7, 18]

*/
#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;

        vector<int> new_num;
        new_num.push_back(nums[0]);

        int max_len = 1;
        for(int i =1; i<len;i++){
            auto it = lower_bound(new_num.begin(), new_num.end(), nums[i]);
            if(it == new_num.end()){
                new_num.push_back(nums[i]);

                if(new_num.size() > max_len)
                    max_len = new_num.size();
            }
            else{
                *it = nums[i];
            }

        }
        return max_len;
    }
};
int main(){
    Solution s;
     vector<int> vect{ 1,2,10, 20, 30,2,3,50 ,11};
    int maxlen = s.lengthOfLIS(vect);
    cout << maxlen<<endl;
    return 0;
}