class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> rightmost;
        vector<vector<int>> ans;
        int lasti = -1000000;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++) rightmost[nums[i]] = i;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == lasti) continue;
            lasti = nums[i];
            int lastj = -1000000;
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[j] == lastj) continue;
                lastj = nums[j];
                if(rightmost[0 - nums[i] - nums[j]] > j) ans.push_back({nums[i], nums[j], 0 - nums[i] - nums[j]});
            } 
        }
        return ans;
    }
};
