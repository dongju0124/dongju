#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);
    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    stack<int> s;
    vector<char> operations;

    int current = 1; // 현재 넣어야 할 수
    for (int i = 0; i < n; ++i) {
        while (s.empty() || s.top() != sequence[i]) {
            if (current > n) {
                cout << "NO" << endl;
                return 0;
            }
            s.push(current++);
            operations.push_back('+');
        }
        if (s.top() == sequence[i]) {
            s.pop();
            operations.push_back('-');
        }
    }

    for (char op : operations) {
        cout << op << '\n';
    }

    return 0;
}
