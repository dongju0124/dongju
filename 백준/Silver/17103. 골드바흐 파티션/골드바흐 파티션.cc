#include <iostream>
using namespace std;

const int MAX = 1000000;
bool isNotPrime[MAX + 1];

void prime() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i * i <= 1000000; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}

int main() {
    prime();

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        int cnt = 0;

        for (int i = 2; i <= N / 2; i++) {
            if (!isNotPrime[i] && !isNotPrime[N - i]) {
                cnt++;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
