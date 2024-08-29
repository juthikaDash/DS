//https://leetcode.com/problems/combination-sum-iv/description/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
                //dp array will also have the base case that is there is 1 way to reach target == 0
                vector<int> dp(target+1,0);
                dp[0] = 1;

                //traverse to calculate the no ways for each target
                for(int i = 1; i<=target; i++){
                    for(int j = 0;j<nums.size();j++){
                        if(i - nums[j] >= 0){
                            dp[i] = dp[i] + dp[i - nums[j]];
                        }
                    }
                }
                return dp[target];
    }
};

