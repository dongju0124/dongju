#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string editor;
    int n;
    cin >> editor >> n;

    stack<char> left_stack, right_stack;

    for (char c : editor) {
        left_stack.push(c);
    }

    while (n--) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (!left_stack.empty()) {
                right_stack.push(left_stack.top());
                left_stack.pop();
            }
        }
        else if (command == 'D') {
            if (!right_stack.empty()) {
                left_stack.push(right_stack.top());
                right_stack.pop();
            }
        }
        else if (command == 'B') {
            if (!left_stack.empty()) {
                left_stack.pop();
            }
        }
        else if (command == 'P') {
            char ch;
            cin >> ch;
            left_stack.push(ch);
        }
    }

    while (!left_stack.empty()) {
        right_stack.push(left_stack.top());
        left_stack.pop();
    }

    while (!right_stack.empty()) {
        cout << right_stack.top();
        right_stack.pop();
    }

    return 0;
}
