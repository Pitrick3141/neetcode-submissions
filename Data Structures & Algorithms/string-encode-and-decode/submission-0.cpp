class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(const auto& s: strs) {
            encoded += s.size() / 100 + '0';
            encoded += (s.size() / 10 % 10) + '0';
            encoded += (s.size() % 10) + '0';
            encoded += s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int cursor = 0;
        while(cursor < s.size()) {
            int l = (s[cursor] - '0') * 100 + (s[cursor + 1] - '0') * 10 + (s[cursor + 2] - '0');
            cursor += 3;
            string payload = "";
            for(int i = 0; i < l; i++) {
                payload += s[cursor + i];
            }
            cursor += l;
            decoded.push_back(payload);
        }
        return decoded;
    }
};
