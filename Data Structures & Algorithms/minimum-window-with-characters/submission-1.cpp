class Solution {
public:
    string minWindow(string s, string t) {
        int required = t.size(), req[256];
        for(int i = 0; i < 256; i++) req[i] = 0;
        bool isRequired[256];
        int l = 0, r = 0, ans = s.size() + 1, ansl = 0, ansr = 0;
        for(int i = 0; i < t.size(); i++) {
            req[t[i]] ++;
            isRequired[t[i]] = true;
        }
        while(r < s.size()) {
            if(isRequired[s[r]]) {
                if(req[s[r]] -- > 0) required --;
            }
            r ++;
            while(required == 0) {
                if(r - l < ans) {
                    ans = r - l;
                    ansl = l;
                    ansr = r;
                }
                if(isRequired[s[l]]) if(++req[s[l]] > 0) required ++;
                l ++;
            }
        }
        string ansStr = "";
        for(int i = ansl; i < ansr; i++) ansStr += s[i];
        return ansStr;
    }
};
