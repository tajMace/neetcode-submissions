class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> expr;
        int result = 0;

        for (auto &token : tokens) {
            if (!isSymbol(token[0]) || token.size() > 1) {
                expr.push(stoi(token));
                continue;
            }

            int next = expr.top();
            expr.pop();

            int result = expr.top();
            expr.pop();

            expr.push(calculate(result, next, token[0]));
        }

        return expr.top();
    }

private:
    bool isSymbol(const char c) {
        switch (c) {
            case '+':
            case '-':
            case '*':
            case '/':
                return true;
        }

        return false;
    }

    int calculate(const int result, const int next, const char operand) {
        switch (operand) {
            case '+': {
                return result + next;
            } case '-': {
                return result - next;
            } case '*': {
                return result * next;
            } case '/': {
                return result / next;
            }
        }

        return INT_MAX;          // error
    }
};
