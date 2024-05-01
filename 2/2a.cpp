#include <stack>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

int evalRPN(string tokens) {
    istringstream iss(tokens);
    string token;
    stack<int> stack;
    while (getline(iss, token, ' ')) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
            stack.pop();
            if (token == "+") stack.push(op1 + op2);
            else if (token == "-") stack.push(op1 - op2);
            else if (token == "*") stack.push(op1 * op2);
            else stack.push(op1 / op2);
        } else {
            stack.push(stoi(token));
        }
    }
    return stack.top();
}

int main() {
    string rpn = "2 3 + 4 *";
    cout << evalRPN(rpn) << endl;  // Output: 20
    return 0;
}
