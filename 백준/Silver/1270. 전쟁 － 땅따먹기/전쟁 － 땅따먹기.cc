#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T;
    cin >> N;
    unordered_map<long long, int> m;

    while (N--) {
        cin >> T;
        m.clear();
        int freqNum = 0;
        long long maxNum = 0;
        for (int i = 0; i < T; i++) {
            long long temp;
            cin >> temp;
            m[temp]++;
        }

        // 가장 많이 나온 군번과 빈도 찾기
        for (const auto& p : m) {
            if (p.second > freqNum) {
                freqNum = p.second;
                maxNum = p.first;
            }
        }

        if (freqNum > T / 2) cout << maxNum << '\n';
        else cout << "SYJKGW\n";
    }
    return 0;
}