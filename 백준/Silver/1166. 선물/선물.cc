#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int N, L, W, H;
    double start = 0;
    double stop;

    cin >> N >> L >> W >> H;
    stop = max(L, max(W, H));

    for (int i = 0; i < 10000; i++) {
        long double mid = (start + stop) / 2;
        if (((long long)(L / mid)) * ((long long)(W / mid)) * ((long long)(H / mid)) >= N) {
            start = mid;
        }
        else {
            stop = mid;
        }
    }

    cout.precision(10);
    cout << fixed << stop;
}
