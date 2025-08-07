#include <iostream>
using namespace std;

int board[17][17];
int N;
int result = 0;

bool canMoveRight(int y, int x) {
    return (x + 1 <= N && board[y][x + 1] == 0);
}

bool canMoveDown(int y, int x) {
    return (y + 1 <= N && board[y + 1][x] == 0);
}

bool canMoveDiagonal(int y, int x) {
    return (y + 1 <= N && x + 1 <= N &&
        board[y][x + 1] == 0 &&
        board[y + 1][x] == 0 &&
        board[y + 1][x + 1] == 0);
}

void dfs(int y, int x, int dir)
{
    if (y == N && x == N) {
        result++;
        return;
    }

    if (dir == 0) { // 가로
        if (canMoveRight(y, x))
            dfs(y, x + 1, 0);
        if (canMoveDiagonal(y, x))
            dfs(y + 1, x + 1, 2);
    }
    else if (dir == 1) { // 세로
        if (canMoveDown(y, x))
            dfs(y + 1, x, 1);
        if (canMoveDiagonal(y, x))
            dfs(y + 1, x + 1, 2);
    }
    else if (dir == 2) { // 대각선
        if (canMoveRight(y, x))
            dfs(y, x + 1, 0);
        if (canMoveDown(y, x))
            dfs(y + 1, x, 1);
        if (canMoveDiagonal(y, x))
            dfs(y + 1, x + 1, 2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];

    dfs(1, 2, 0);

    cout << result << "\n";
    return 0;
}
