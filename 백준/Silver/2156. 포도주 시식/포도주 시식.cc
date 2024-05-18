#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int wine[10000];
    int dp[10000];

    for (int i = 0; i < n; ++i) {
        cin >> wine[i];
    }

    if (n == 1) {
        cout << wine[0] << endl;
        return 0;
    }

    if (n == 2) {
        cout << wine[0] + wine[1] << endl;
        return 0;
    }

    dp[0] = wine[0];
    dp[1] = wine[0] + wine[1];
    dp[2] = max({ wine[0] + wine[1], wine[0] + wine[2], wine[1] + wine[2] });

    for (int i = 3; i < n; ++i) {
        dp[i] = max({ dp[i - 1], dp[i - 2] + wine[i], dp[i - 3] + wine[i - 1] + wine[i] });
    }

    cout << dp[n - 1] << endl;
    return 0;
}
