//https://leetcode.com/problems/house-robber-ii/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
   int helper(vector<int>& nums) {
       int rob1 = 0, rob2=0;
       for(int n: nums){
        int temp = max(rob1+n, rob2);
        rob1 = rob2;
        rob2=temp;
       } 
       return rob2;
    }
    int rob(vector<int>& nums) {
        //base case
        if(nums.size() == 0){ return 0;}
        if(nums.size() == 1){ return nums[0];}

        int skipped_house = 0;
        //skipping the last house
        skipped_house = nums.back();
        nums.pop_back();
        int option1 = helper(nums);

        //skipping the first hosue
        nums.push_back(skipped_house);
        skipped_house = nums.front();
        nums.erase(nums.begin());
        int option2 = helper(nums);

        return max(option1, option2);
    }
};
