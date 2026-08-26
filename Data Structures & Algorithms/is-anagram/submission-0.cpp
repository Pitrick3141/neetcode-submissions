class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26];
        if(s.size() != t.size()) return false;
        for(int i = 0; i < 26; i++) count[i] = 0;
        for(int i = 0; i < s.size(); i++) {
            count[s[i] - 'a'] ++;
        }
        for(int i = 0; i < t.size(); i++) {
            count[t[i] - 'a'] --;
            if(count[t[i] - 'a'] < 0) return false;
        }
        for(int i = 0; i < 26; i++) if(count[i] != 0) return false;
        return true;
    }
};
