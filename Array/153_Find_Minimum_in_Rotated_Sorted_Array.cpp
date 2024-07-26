//153_Find_Minimum_in_Rotated_Sorted_Array.cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0];
        int low = 0;
        int high = nums.size() -1;
        //int mid = 0;

        while(low <= high)
        {

            
            if(nums[low] <= nums[high])
            {
                res = min(res, nums[low]);
                break;
            }

            int mid = (low + high )/2;
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[low])
            {
                
                low = mid + 1;
                //res = min(res, nums[low]);
            }
            else //if(nums[mid] <= nums[high])
            {
               
                high = mid -1;
                //res = min(res, nums[mid]);
            }

            
         
        }
        return res;
    }
};