#include <iostream>
using namespace std;

int board[5][5];
bool visited[1000000];
int cnt = 0;

void dfs(int x, int y, int sum, int depth) {
    if (depth == 6) {
        if (!visited[sum]) {
            visited[sum] = true;
            cnt++;
        }
        return;
    }

    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { -1, 1, 0, 0 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) 
            continue;

        dfs(nx, ny, sum * 10 + board[nx][ny], depth + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> board[i][j];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            dfs(i, j, board[i][j], 1);

    cout << cnt << "\n";
}
