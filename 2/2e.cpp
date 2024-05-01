#include <stack>
#include <string>
#include <iostream>
using namespace std;

bool isBalanced(const string& expression) {
    stack<char> stack;
    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) return false;
            char top = stack.top();
            stack.pop();
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    string expression = "{[()]}";
    string expression2 = "{[()]{}";
    cout << (isBalanced(expression) ? "Balanced" : "Not balanced((((") << endl;
    cout << (isBalanced(expression2) ? "Balanced" : "Not balanced((((") << endl;
    return 0;
}
