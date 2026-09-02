class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> result;
        for(int i = 0; i < temperatures.size(); i++) {
            result.push_back(0);
            while(!st.empty() && temperatures[i] > st.top().first) {
                result[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        return result;
    }
};
