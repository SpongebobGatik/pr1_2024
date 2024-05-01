#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
    int value;
    vector<Node*> children;
};

void depthFirstSearch(Node* root) {
    stack<Node*> stack;
    stack.push(root);
    while (!stack.empty()) {
        Node* node = stack.top();
        stack.pop();
        cout << "Узел: " << node->value << endl;
        for (Node* child : node->children) {
            stack.push(child);
        }
    }
}

int main() {
    // Создание узлов
    Node node1 {1, {}};
    Node node2 {2, {}};
    Node node3 {3, {}};
    Node node4 {4, {}};
    Node node5 {5, {}};

    // Создание связей между узлами
    node1.children = {&node2, &node3};
    node2.children = {&node4, &node5};

    // Вызов функции обхода дерева в глубину
    depthFirstSearch(&node1);

    return 0;
}
