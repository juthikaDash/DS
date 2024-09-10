//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i =0,j=0;
        if(nums.size() == 0){
            return 0;
        }
        for(;i <nums.size()-1;i++){
            if(nums[i] !=nums[i+1]){
                nums[j]=nums[i];
                j++;
            }
        }
        nums[j] = nums[i];
        j++;
        return j;
    }
};