#include <stack>
#include <iostream>
using namespace std;

struct Operation {
    string action;
    int value;
};

stack<Operation> operations;

void perform(const Operation& op) {
    cout << "Performing operation: " << op.action << " with value: " << op.value << endl;
    operations.push(op);
}

void undo() {
    if (!operations.empty()) {
        Operation op = operations.top();
        operations.pop();
        cout << "Undoing operation: " << op.action << " with value: " << op.value << endl;
    }
}

int main() {
    perform({"add", 5});
    perform({"subtract", 3});
    undo();
    return 0;
}
