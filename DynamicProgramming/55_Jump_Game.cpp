//https://leetcode.com/problems/jump-game/description/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_reach =0;
        for(int i=0; i<nums.size(); i++){
            if(i+nums[i] > max_reach){
                max_reach = nums[i]+i;
            }
            if(i == max_reach){ break;}
        }

        return max_reach >= nums.size()-1;
    }
};
