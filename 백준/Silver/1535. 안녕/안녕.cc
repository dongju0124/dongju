#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> L(N); // 체력 소모 배열
    vector<int> J(N); // 기쁨 배열

    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> J[i];
    }

    // DP 테이블 초기화
    vector<int> dp(101, 0); // 체력은 최대 100이므로 크기 101로 설정

    for (int i = 0; i < N; i++) {
        for (int hp = 100; hp > 0; hp--) {
            if (hp > L[i]) { // 체력이 충분할 때만 선택 가능
                dp[hp] = max(dp[hp], dp[hp - L[i]] + J[i]);
            }
        }
    }

    // 최대 기쁨 찾기
    int maxJoy = 0;
    for (int hp = 1; hp <= 100; hp++) {
        maxJoy = max(maxJoy, dp[hp]);
    }

    cout << maxJoy << endl;

    return 0;
}
