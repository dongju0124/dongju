#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

const int MAX = 1000;
int N, M;
int map[MAX][MAX];
bool visited[MAX][MAX][2]; // [x][y][0]: 벽을 부수지 않고 방문, [x][y][1]: 벽을 부수고 방문

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

struct Node {
    int x, y, dist, wall;
};

int bfs() {
    queue<Node> q;
    q.push({ 0, 0, 1, 0 });
    visited[0][0][0] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        int x = current.x;
        int y = current.y;
        int dist = current.dist;
        int wall = current.wall;

        if (x == N - 1 && y == M - 1) {
            return dist;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == 0 && !visited[nx][ny][wall]) {
                    visited[nx][ny][wall] = true;
                    q.push({ nx, ny, dist + 1, wall });
                }
                if (map[nx][ny] == 1 && wall == 0 && !visited[nx][ny][1]) {
                    visited[nx][ny][1] = true;
                    q.push({ nx, ny, dist + 1, 1 });
                }
            }
        }
    }

    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }

    cout << bfs() << endl;
    return 0;
}
