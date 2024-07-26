//https://leetcode.com/problems/3sum/
#define TARGET 0

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int start =0, end =0, len = nums.size();

        if (len == 0 ){ return res;}

        for (int i =0; i< len; i++){
            if (i != 0 && (nums[i] == nums[i-1]))
            {
                continue;
            }
            start = i+1;
            end = len-1;
            //cout <<"i:"<<i<< "   start:"<< start <<"  end:"<<end <<endl;

            while(start < end)
            {
                //cout << nums[i]<<":"<< nums[start]<<":"<<nums[end]<< endl;
                if((nums[i] + nums[start] + nums[end]) == TARGET)
                {
                    //cout << nums[i]<<":"<< nums[start]<<":"<<nums[end]<< endl;
                    vector<int> match_list = {nums[i], nums[start],nums[end]};
                    res.push_back(match_list);
                    start++;
                    while( (start < end) && (nums[start] == nums[start-1])){ start++;}
                }
                else if ((nums[i] + nums[start] + nums[end]) > TARGET ){
                    --end;
                }
                else
                    ++start;
            } // end of while
        } // end of for
        return res;
    }
};
