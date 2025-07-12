#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> tower(N);
    vector<int> receive(N, 0);

    for (int i = 0; i < N; ++i)
        cin >> tower[i];

    stack<int> s;

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && tower[s.top()] < tower[i]) {
            s.pop();
        }

        if (!s.empty()) {
            receive[i] = s.top() + 1;
        }
        else {
            receive[i] = 0;
        }

        s.push(i);
    }

    for (int i = 0; i < N; ++i)
        cout << receive[i] << ' ';

    return 0;
}
