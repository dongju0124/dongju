#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int iceberg[301][301];
bool visited[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void dfs(int y, int x) {
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= N || nx >= M) 
            continue;
        if (!visited[ny][nx] && iceberg[ny][nx] > 0)
            dfs(ny, nx);
    }
}

int countIceberg() {
    memset(visited, false, sizeof(visited));
    int cnt = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (iceberg[i][j] > 0 && !visited[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void melt() {
    int decrease[301][301] = { 0 };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (iceberg[i][j] > 0) {
                int water = 0;
                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if (ny < 0 || nx < 0 || ny >= N || nx >= M) 
                        continue;
                    if (iceberg[ny][nx] == 0) 
                        water++;
                }
                decrease[i][j] = water;
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            iceberg[i][j] = max(0, iceberg[i][j] - decrease[i][j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> iceberg[i][j];

    int year = 0;
    while (true) {
        int cnt = countIceberg();
        if (cnt >= 2) {
            cout << year;
            break;
        }
        if (cnt == 0) {
            cout << 0;
            break;
        }

        melt();
        year++;
    }
    return 0;
}
