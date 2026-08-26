class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> ans;
        for(const auto &s: strs) {
            string sorted = s;
            sort(sorted.begin(), sorted.end());
            if(anagrams.contains(sorted)) {
                anagrams[sorted].push_back(s);
            }
            else anagrams[sorted] = vector<string>({s});
        }
        for(const auto& [sorted, arr]: anagrams) {
            ans.push_back(arr);
        }
        return ans;
    }
};
