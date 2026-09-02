class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> lmax, rmax;
        for(int i = 0; i < height.size(); i++) {
            lmax.push_back(0);
            rmax.push_back(0);
        }
        for(int i = 1; i < height.size(); i++) lmax[i] = max(lmax[i-1], height[i-1]);
        for(int i = height.size() - 2; i >= 0; i--) rmax[i] = max(rmax[i+1], height[i+1]);
        for(int i = 0; i < height.size(); i++) ans += max(min(lmax[i], rmax[i]) - height[i], 0);
        return ans;
    }
};
