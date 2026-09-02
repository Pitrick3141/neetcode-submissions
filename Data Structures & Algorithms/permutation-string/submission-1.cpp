class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int required[26], count = s1.size();
        bool isRequired[26];
        for(int i = 0; i < 26; i++) required[i] = 0;
        for(const auto &ch : s1) {
            required[ch - 'a'] ++;
            isRequired[ch - 'a'] = true;
        }
        for(int i = 0; i < s1.size(); i++) if(isRequired[s2[i] - 'a'] && required[s2[i] - 'a'] -- > 0) count --;
        for(int i = 0; i + s1.size() < s2.size(); i++) {
            if(count == 0) return true;
            if(isRequired[s2[i + s1.size()] - 'a'] && required[s2[i + s1.size()] - 'a'] -- > 0) count --;
            if(isRequired[s2[i] - 'a'] && ++ required[s2[i] - 'a'] > 0) count ++;
        }
        if(count == 0) return true;
        return false;
    }
    
};
