class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> freq;
        for(int i = 0; i < 2010;i ++) freq.push_back({0,i-1000});
        for(const auto& it : nums) {
            freq[it+1000].first ++;
        }
        sort(freq.begin(), freq.end(), [](const pair<int,int> &x, const pair<int,int> &y) {
            return x.first > y.first;
            });
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};
