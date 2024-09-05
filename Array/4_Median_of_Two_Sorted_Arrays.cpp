//https://leetcode.com/problems/median-of-two-sorted-arrays/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
//Doing the binary search to partition both the array such that number of element of each side is same and every element on the left side is less than evey element on the right side
//partition X + partion y = (x+y+1)/2
//Found
//maxleftX <= minRightY
//maxleftY<= minRightX
//else if
//maxleftX> minrightY // too much of left
// moveleft in x
//else move towords y
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int x = nums1.size();
        int y = nums2.size();
        //nums1 is empty
        if(x == 0){
            if(y%2 != 0){
                return nums2[y/2];
            }
            else{
                auto mid = y/2;
                return((double)(nums2[mid]+nums2[mid+1])/2);
            }
        }
        //nums2 is empty
        if(y == 0){
            if(x%2 != 0){
                return nums1[x/2];
            }
            else{
                auto mid = x/2;
                return((double)(nums1[mid]+nums1[mid+1])/2);
            }
        }

        //if(nums1 is greater then switch
        if(x>y){
            return findMedianSortedArrays(nums2,nums1);
        }
        int low =0; 
        int high = x;
        while(low<=high){
            int partition_x = (low+high)/2;
            int partition_y = (x+y+1)/2 - partition_x;

            //find the leftmax and right min for partision
            double x_left_max = (partition_x ==0)? INT_MIN : nums1[partition_x-1];
            double x_right_min = (partition_x == x)?INT_MAX: nums1[partition_x];

            double y_left_max = (partition_y == 0)? INT_MIN: nums2[partition_y-1];
            double y_right_min = (partition_y == y)? INT_MAX : nums2[partition_y];

            //check the partition is correct or not
            if(x_left_max <= y_right_min and x_right_min >= y_left_max ){
                //odd nums
                if((x+y)%2 !=0){
                    return max(x_left_max,y_left_max);
                }
                else //even
                {
                    return ((max(x_left_max,y_left_max)+min(x_right_min,y_right_min))/2);
                }
            }

            //partition not correct then find the new partition
            //we are too far on the right
            else if(x_left_max > y_right_min){
                high = partition_x -1;
            }
            else{
                low = partition_x +1;
            }
        }
        return -1;
    }

};
