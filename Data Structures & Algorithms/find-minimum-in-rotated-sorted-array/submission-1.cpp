class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;
        if(nums[l] < nums[r]) return nums[l];
        while(l < r - 1) {
            int x = (l + r) >> 1;
            if(nums[l] < nums[x]) l = x;
            else r = x;
        }
        return nums[r];
    }
};
