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
    bool isValidClosing(char c, stack<char>& open) {
        return (
            isClosingBracket(c) && 
            !open.empty() && 
            open.top() == getMatch(c)
        );
    }

    bool isOpeningBracket(char c) {
        return (
            c == '(' ||
            c == '[' ||
            c == '{'
        ) ? true : false;
    }

    bool isClosingBracket(char c) {
        return (
            c == ')' ||
            c == ']' ||
            c == '}'
        ) ? true : false;
    }

    char getMatch(char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        if (c == '}') return '{';
        return 0;
    }
};



