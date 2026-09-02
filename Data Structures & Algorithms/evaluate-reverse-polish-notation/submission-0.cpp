class Solution {
    stack<string> tok;
public:
    int evalRPN(vector<string>& tokens) {
        for(const auto& ch : tokens) tok.push(ch);
        return evalOnce();
    }
    int evalOnce() {
        string current = tok.top();
        tok.pop();
        if(current == "+") {
            return evalOnce() + evalOnce();
        }
        else if(current == "-") {
            int tmp = evalOnce();
            return evalOnce() - tmp;
        }
        else if(current == "*") {
            return evalOnce() * evalOnce();
        }
        else if(current == "/") {
            int tmp = evalOnce();
            return evalOnce() / tmp;
        }
        else return stoi(current);
    }
};
