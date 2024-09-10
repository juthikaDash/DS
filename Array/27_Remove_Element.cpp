//https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        for(int i = 0; i< nums.size();i++)
        {
            if(nums[i] == val)
            { 
               nums.erase (nums.begin()+i);
               i = i-1;
            }
            else
                continue;
        }
        return nums.size();
    }
};
