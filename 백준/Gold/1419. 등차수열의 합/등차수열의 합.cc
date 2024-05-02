#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int l, r, k;
    cin >> l >> r >> k;

    if (k == 2) {
        cout << max(0, r - max(l, 3) + 1) << endl;
    }
    else if (k == 3) {
        cout << max(0, r / 3 - (max(l, 6) - 1) / 3) << endl;
    }
    else if (k == 4) {
        cout << max(0, r / 2 - (max(l, 14) - 1) / 2) + (l <= 10 && 10 <= r) << endl;
    }
    else {
        cout << max(0, r / 5 - (max(l, 15) - 1) / 5) << endl;
    }

    return 0;
}