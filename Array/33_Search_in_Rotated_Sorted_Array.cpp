//https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low =0, high = nums.size()-1;

        while(low<= high)
        {
            int mid = (low + high)/2;

            //case 1
            if(nums[mid] ==  target)
                return mid;

            //case 2:
            else if( nums[mid] <= nums[high])
            {
                if(target > nums[mid] && target <= nums[high])
                {
                    low = mid +1;
                }
                else
                    high = mid -1;
            }
            else{
                     if(nums[low] <= target && target < nums[mid])
                     {
                         high = mid -1;
                     }
                     else
                        low = mid +1;
            }
           
        }
        return -1;
    }
};