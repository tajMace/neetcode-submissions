class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        for (auto &c : s) {
            if (isOpeningBracket(c)) {
                open.push(c);
            } else if (isValidClosing(c, open)) {
                open.pop();
            } else {
                return false;
            }
        }

        return open.empty() ? true : false;
    }

private:
    bool isValidClosing(const char c, stack<char>& open) {
        return (
            isClosingBracket(c) && 
            !open.empty() && 
            open.top() == getMatch(c)
        );
    }

    bool isOpeningBracket(const char c) {
        return (
            c == '(' ||
            c == '[' ||
            c == '{'
        );
    }

    bool isClosingBracket(const char c) {
        return (
            c == ')' ||
            c == ']' ||
            c == '}'
        );
    }

    char getMatch(const char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';
        return 0;
    }
};



