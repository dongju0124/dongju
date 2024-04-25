#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입력값을 저장할 변수 선언
    int N, S, M;
    // 곡의 수 N, 시작 볼륨 S, 최대 볼륨 M 입력
    cin >> N >> S >> M;

    // 각 곡의 볼륨 차이를 저장할 벡터 선언 및 입력
    vector<int> volume(N);
    for (int i = 0; i < N; ++i) {
        cin >> volume[i];
    }

    // 동적 계획법을 위한 2차원 dp 배열 선언 및 초기화
    vector<vector<bool>> dp(N + 1, vector<bool>(M + 1, false));
    dp[0][S] = true;

    // 각 곡에 대해 가능한 경우를 탐색하는 이중 반복문
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (dp[i][j]) {
                // 이전 곡에서 가능한 볼륨을 기반으로 현재 곡의 볼륨을 계산
                int next1 = j - volume[i];
                int next2 = j + volume[i];
                // 가능한 볼륨이 범위 내에 있다면 dp 배열 업데이트
                if (next1 >= 0) dp[i + 1][next1] = true;
                if (next2 <= M) dp[i + 1][next2] = true;
            }
        }
    }

    // 마지막 곡의 가능한 볼륨 중 최댓값을 구함
    int result = -1;
    for (int i = 0; i <= M; ++i) {
        if (dp[N][i]) {
            result = i;
        }
    }

    // 결과 출력
    cout << result << endl;

    return 0;
}
