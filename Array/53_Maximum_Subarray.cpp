//https://leetcode.com/problems/maximum-subarray/description/
//Kadanes algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumL = nums[0];
        int sumG = nums[0];
       
       for(int i = 1; i< nums.size(); i++)
       {
           sumL = max( nums[i], sumL+nums[i]);
           sumG = max(sumG, sumL);
       }

       return sumG;

    }
};