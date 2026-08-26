class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> first;
        for(int i = 0; i < nums.size(); i++) {
            if(first.contains(nums[i])) return {first[nums[i]], i};
            first[target - nums[i]] = i;
        }
    }
};
