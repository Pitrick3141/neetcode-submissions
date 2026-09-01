class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if(nums[l] >= nums[r]) {
            while(l < r - 1) {
                int x = (l + r) >> 1;
                if(nums[l] < nums[x]) l = x;
                else r = x;
            }
            if(nums[r] >= target) return nums[r] == target ? r : -1;
            if(nums[nums.size() - 1] >= target) {
                l = r + 1;
                r = nums.size() - 1;
            }
            else {
                l = 0;
                r = r - 1;
            }
        }
        
        while(l <= r) {
            int x = (l + r) >> 1;
            if(nums[x] == target) return x;
            else if(nums[x] < target) l = x + 1;
            else r = x - 1;
        }
        return -1;
    }
};
