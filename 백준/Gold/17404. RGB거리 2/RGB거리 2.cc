#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    int result = INF;

    // 첫 번째 집의 색상을 고정하고 최소 비용을 찾음
    for (int first_color = 0; first_color < 3; first_color++) {
        vector<vector<int>> dp(N, vector<int>(3, INF));

        // 첫 번째 집의 색상을 first_color로 설정
        dp[0][first_color] = cost[0][first_color];

        // DP 테이블 채우기
        for (int i = 1; i < N; i++) {
            dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }

        // 마지막 집의 색이 첫 번째 집의 색과 겹치지 않도록 고려
        for (int last_color = 0; last_color < 3; last_color++) {
            if (first_color != last_color) {
                result = min(result, dp[N - 1][last_color]);
            }
        }
    }

    cout << result << endl;
    return 0;
}
