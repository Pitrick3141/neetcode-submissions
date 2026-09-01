class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> corr;
        corr['('] = ')';
        corr['['] = ']';
        corr['{'] = '}';
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
            else if(st.empty()) return false;
            else if(s[i] != corr[st.top()]) return false;
            else st.pop();
        }
        if(!st.empty()) return false;
        return true;
    }
};
