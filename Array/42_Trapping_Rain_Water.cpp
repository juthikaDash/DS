//https://leetcode.com/problems/trapping-rain-water/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //size of the array
        int n = height.size();

        //base case
        if(n<2){
            return 0;
        }

        int leftmax = height[0];
        int rightmax = height[n-1];
        int left = 1;
        int right = n-2;
        int trapperWater = 0;

        while(left<=right){
            if(leftmax < rightmax){
                if(height[left] >= leftmax){
                    leftmax = height[left];
                }
                else{
                    trapperWater +=leftmax - height[left];
                }
                left++;
            }
            else{
                if(rightmax <= height[right] ){
                    rightmax = height[right];
                }
                else{
                    trapperWater += rightmax - height[right];
                }
                right--;
            }
        }

        return trapperWater;
    }
};
