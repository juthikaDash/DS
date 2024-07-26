//https://leetcode.com/problems/two-sum/description/
//time and space complexity 0(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

            vector<int> result;

            unordered_map<int, int> list;
            for(int i = 0; i < nums.size();i++){
                int diff = target -nums[i];
                auto it = list.find(diff);

                if(it != list.end()){
                    result.push_back(it->second);
                    result.push_back(i);
                }
                list[nums[i]] = i;
            }
            return result;

    }
};