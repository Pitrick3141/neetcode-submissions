class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> last;
        int length = 0, left = 0;
        for(int i = 0; i < s.size(); i++) {
            if(last[s[i]]) left = max(left, last[s[i]]);
            last[s[i]] = i + 1;
            length = max(length, i - left + 1);
        }
        return length;
    }
};
