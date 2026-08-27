class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, ans = 0;
        int freq[26], maxFreq = -1;
        char freqChar;
        for(int i = 0; i < 26; i++) freq[i] = 0;
        while(r < s.size()) {
            if(++freq[s[r] - 'A'] > maxFreq) {
                maxFreq = freq[s[r] - 'A'];
                freqChar = s[r];
            }
            r++;
            while(r - l > maxFreq + k) {
                freq[s[l] - 'A'] --;
                if(freq[s[l] - 'A'] + 1 == maxFreq) {
                    maxFreq --;
                    for(int i = 0; i < 26; i++) maxFreq = max(maxFreq, freq[i]);
                }
                l ++;
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
