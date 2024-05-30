#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int x;
    cin >> x;

    unordered_set<int> seen;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int target = x - numbers[i];
        if (seen.find(target) != seen.end()) {
            ++count;
        }
        seen.insert(numbers[i]);
    }

    cout << count << endl;

    return 0;
}
