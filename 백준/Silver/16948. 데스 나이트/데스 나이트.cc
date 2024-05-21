#include <iostream>
#include <queue>
using namespace std;

int N;
int map[201][201];
bool visited[201][201];
queue<pair<int, int>> q;

int dy[] = { -1,1,-2,2,-1,1 };
int dx[] = { -2,-2,0,0,2,2 };

void BFS(int y, int x) {
    map[y][x] = 0;
    visited[y][x] = true;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny > N || nx > N)
                continue;
            if (!visited[ny][nx]) {
                visited[ny][nx] = true;
                map[ny][nx] = map[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main() {
    cin >> N;

    int r1, c1, r2, c2; //r1 c1 r2 c2
    cin >> r1 >> c1 >> r2 >> c2;

    BFS(c1, r1);

    if (map[c2][r2] == 0)
        cout << -1;
    else
        cout << map[c2][r2];

}
