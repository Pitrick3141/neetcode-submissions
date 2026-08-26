class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,bool> existed;
        for(int i = 0; i < nums.size(); i++) {
            if(existed.contains(nums[i])) return true;
            existed[nums[i]] = true;
        }
        return false;
    }
};