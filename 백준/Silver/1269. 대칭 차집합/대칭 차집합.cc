#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<int> A, B;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        A.insert(num);
    }

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        B.insert(num);
    }

    int common = 0;

    for (auto num : A) {
        if (B.find(num) != B.end()) {
            common++;
        }
    }

    int diff = A.size() + B.size() - 2 * common;
    cout << diff << '\n';

    return 0;
}
