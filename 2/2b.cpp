#include <stack>
#include <iostream>
using namespace std;

void funcA();
void funcB();

stack<void (*)()> callStack;

int main() {
    callStack.push(funcA);
    callStack.push(funcB);
    while (!callStack.empty()) {
        callStack.top()();
        callStack.pop();
    }
    return 0;
}

void funcA() {
    cout << "Function A" << endl;
}

void funcB() {
    cout << "Function B" << endl;
}
