class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> rightmost;
        map<pair<int, int>, bool> used;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i++) rightmost[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i + 1; j < nums.size(); j++) 
                if(rightmost[0 - nums[i] - nums[j]] > j) {
                    int small = min(min(nums[i], nums[j]), min(nums[j], 0 - nums[i] - nums[j]));
                    int large = max(max(nums[i], nums[j]), max(nums[j], 0 - nums[i] - nums[j]));
                    if(used[{small, large}]) continue;
                    ans.push_back({nums[i], nums[j], 0 - nums[i] - nums[j]});
                    used[{small, large}] = true;
                }
        return ans;
    }
};
