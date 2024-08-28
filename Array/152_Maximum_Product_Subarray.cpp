//https://leetcode.com/problems/maximum-product-subarray/description/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int maxProdL = nums[0];
        int minProdL = nums[0];

        for (int i =1;i<nums.size();i++)
        {
            if(nums[i] <0)
            {
                swap(maxProdL, minProdL);
            }
            maxProdL = max(nums[i], nums[i]*maxProdL);
            minProdL = min(nums[i], nums[i]*minProdL);

            maxProd = max(maxProdL, maxProd);
        }

        return maxProd;
    }
};
