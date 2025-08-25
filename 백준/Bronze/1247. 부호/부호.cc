#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = 0; t < 3; t++) {
        int n;
        cin >> n;

        __int128 sum = 0;  // 128비트 정수
        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            sum += x;
        }

        if (sum > 0) 
            cout << "+\n";
        else if (sum < 0) 
            cout << "-\n";
        else 
            cout << "0\n";
    }
    return 0;
}
