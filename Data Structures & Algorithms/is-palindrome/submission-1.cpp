class Solution {
    bool isAlphaNumeric(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
    char normalize(char c) {
        if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
        return c;
    }
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(!isAlphaNumeric(s[l])) l++;
        while(!isAlphaNumeric(s[r])) r--;
        while(l < r) {
            if(normalize(s[l]) != normalize(s[r])) return false;
            do l++; while(l < r && !isAlphaNumeric(s[l]));
            do r--; while(l < r && !isAlphaNumeric(s[r]));
        }
        return true;
    }
};
