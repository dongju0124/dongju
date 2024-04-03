#include <iostream>
#include <vector>

using namespace std;

int N, M;
int dx[4] = { 1, -1, 0 , 0 };
int dy[4] = { 0, 0, 1, -1 };

int arr[500][500];
bool visited[501][501];
int ans;

void dfs(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        ans = max(sum, ans);
        return;
    }
    if (!visited[y][x]) {
        sum += arr[y][x];
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;

            visited[y][x] = true;
            dfs(nx, ny, cnt + 1, sum);
            visited[y][x] = false;
        }
    }

    // ㅓ
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < N)
        ans = max(ans, arr[y][x - 1] + arr[y - 1][x] + arr[y][x] + arr[y + 1][x]);
    // ㅏ
    if (x + 1 < M && y - 1 >= 0 && y + 1 < N)
        ans = max(ans, arr[y][x + 1] + arr[y - 1][x] + arr[y][x] + arr[y + 1][x]);
    // ㅗ
    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < M)
        ans = max(ans, arr[y][x - 1] + arr[y - 1][x] + arr[y][x] + arr[y][x + 1]);
    // ㅜ
    if (x - 1 >= 0 && y + 1 < N && x + 1 < M)
        ans = max(ans, arr[y][x - 1] + arr[y + 1][x] + arr[y][x] + arr[y][x + 1]);
}


int main(void) {

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            dfs(j, i, 0, 0);
    }

    cout << ans;
}