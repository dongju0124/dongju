#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> rPrefix, uPrefix, xPrefix;

// 조건 만족하는 최소 index를 찾기 위한 이분 탐색
bool canReach(int x, int y, int N) {
    int left = 0, right = N;

    while (left <= right) {
        int mid = (left + right) / 2;
        int r = rPrefix[mid];
        int u = uPrefix[mid];
        int xDiag = xPrefix[mid];

        // 필요한 이동량
        int dx = x - 1;
        int dy = y - 1;

        // X 명령어를 얼마나 쓸 수 있냐?
        int useX = min({xDiag, dx, dy});

        // 나머지는 R과 U로 커버 가능해야 함
        int remainX = dx - useX;
        int remainY = dy - useX;

        if (r >= remainX && u >= remainY) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return (left <= N);
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string root;
    cin >> root;

    // 누적 벡터 초기화 (0~N)
    rPrefix.assign(N + 1, 0);
    uPrefix.assign(N + 1, 0);
    xPrefix.assign(N + 1, 0);

    // 누적 계산
    for (int i = 0; i < N; i++) {
        rPrefix[i + 1] = rPrefix[i];
        uPrefix[i + 1] = uPrefix[i];
        xPrefix[i + 1] = xPrefix[i];

        if (root[i] == 'R') rPrefix[i + 1]++;
        else if (root[i] == 'U') uPrefix[i + 1]++;
        else if (root[i] == 'X') xPrefix[i + 1]++;
    }

    int K;
    cin >> K;

    int count = 0;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        if (canReach(x, y, N)) {
            count++;
        }
    }

    cout << count << '\n';
    return 0;
}
