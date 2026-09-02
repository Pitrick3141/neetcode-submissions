class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> count;
        set<int> window;
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            count[nums[i]] ++;
            window.insert(nums[i]);
        }
        ans.push_back(*window.rbegin());
        for(int i = 0; i + k < nums.size(); i++) {
            count[nums[i + k]] ++;
            window.insert(nums[i + k]);
            if(-- count[nums[i]] == 0) window.erase(nums[i]);
            ans.push_back(*window.rbegin());
        }
        return ans;
    }
};
