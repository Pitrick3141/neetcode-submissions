class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, maxa = 0;
        int maxl = -1, maxr = -1;
        while(l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            maxa = max(maxa, area);
            maxl = max(maxl, heights[l]);
            maxr = max(maxr, heights[r]);
            if(heights[l] < heights[r]) {
                do l++; while(l < r && heights[l] <= maxl);
            }
            else {
                do r--; while(l < r && heights[r] <= maxr);
            }
        }
        return maxa;
    }
};
