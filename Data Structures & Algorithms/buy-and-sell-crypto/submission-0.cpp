class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxs;
        int maxSell = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            maxSell = max(maxSell, prices[i]);
            maxs.push_back(maxSell);
        }
        maxSell = 0;
        for(int i = 0; i < prices.size(); i++)
            maxSell = max(maxSell, maxs[prices.size() - i - 1] - prices[i]);
        return maxSell;
    }
};
