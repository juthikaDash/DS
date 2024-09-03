//https://leetcode.com/problems/merge-sorted-array/description/?envType=company&envId=amazon&favoriteSlug=amazon-thirty-days
/*
    - Give both the array are sorted
    - Final array will be part of nums1
    - If nums2 has no element then just return
    - If nums1 has no element then copy data from nums2 -> nums1 and return
    - Get the length of nums1
    - compare the last 2 nums from the sorted array and copy the one which is larget to nums1[len -i]
    - Keep checking till both i > 0 and j >0
    - after the while loop lets check if any of the array has some more element then copy that,
    - if nums2 has more element then just copy to the remaining free space
    - if nums1 has more element then nothing to do as it is already in the require array

    Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    Output: [1,2,2,3,5,6]

    Input: nums1 = [1], m = 1, nums2 = [], n = 0
    Output: [1]

    Input: nums1 = [0], m = 0, nums2 = [1], n = 1
    Output: [1]

*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //when 2nd array does not have any element
        if(n == 0){ return;}
        if(m == 0){
            int i = 0;
            for(int data: nums2){
                nums1[i] = data;
                i++;
            }
        }

        int len = nums1.size() -1;
        while(m>0 and n>0){
            if(nums1[m-1] > nums2[n-1]){
                nums1[len] = nums1[m-1];
                m--;
            }
            else{
                nums1[len] = nums2[n-1];
                n--;
            }
            len--;

            while(m==0 and n !=0){
                nums1[len] = nums2[n-1];
                n--;
                len--;
            }
        }
    }
};
