#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;

int M, N;
int tomato[MAX][MAX];
int days[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isInside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int bfs() {
    queue<pair<int, int>> q;

    // 초기 익은 토마토들을 큐에 넣음
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 1) {
                q.push({ i, j });
                days[i][j] = 0;
            }
        }
    }

    int result = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isInside(nx, ny) && tomato[nx][ny] == 0) {
                tomato[nx][ny] = 1;
                q.push({ nx, ny });
                days[nx][ny] = days[x][y] + 1;
                result = max(result, days[nx][ny]);
            }
        }
    }

    // 모든 토마토가 익었는지 확인
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0) {
                return -1; // 모두 익지 못하는 상황
            }
        }
    }

    return result;
}

int main() {
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
        }
    }

    int result = bfs();

    if (result == -1) {
        cout << -1 << endl;
    }
    else {
        cout << result << endl;
    }

    return 0;
}
