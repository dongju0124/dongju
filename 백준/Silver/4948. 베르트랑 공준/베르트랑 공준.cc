#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 에라토스테네스의 체
    vector<bool> is_prime(123456 * 2 + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= 123456 * 2; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= 123456 * 2; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int n;
    while (cin >> n && n != 0) {
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (is_prime[i]) 
                cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}
