class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for (auto &c : s) {
            switch (c) {
                case '(':
                case '[':
                case '{':
                    open.push(c);
                    break;
                case ')':
                case ']':
                case '}':
                    if (open.empty() || open.top() != getMatch(c)) {
                        return false;
                    }
                    open.pop();
                    break;
                default:
                    return false;
            }
        }

        return open.empty() ? true : false;
    }

private:
    char getMatch(char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';
        return 0;
    }
};



