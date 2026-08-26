class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int, int>> intervals;
        int ans = 0;
        for(const auto& n: nums) {
            if(intervals.contains(n)) continue;
            int l = n, r = n;
            if(intervals.contains(n+1)) r = intervals[n+1].second;
            if(intervals.contains(n-1)) l = intervals[n-1].first;
            intervals[n] = {l,r};
            ans = max(ans, r - l + 1);
            intervals[l].second = r;
            intervals[r].first = l;
        }
        return ans;
    }
};
