#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
vector<vector<int>> a;
vector<vector<bool>> v;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

vector<pair<int, int>> bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> group;

    q.push({ startX, startY });
    v[startX][startY] = true;
    group.push_back({ startX, startY });

    int sum = a[startX][startY];

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (v[nx][ny]) continue;

            int diff = abs(a[x][y] - a[nx][ny]);
            if (diff >= L && diff <= R) {
                v[nx][ny] = true;
                q.push({ nx, ny });
                group.push_back({ nx, ny });
                sum += a[nx][ny];
            }
        }
    }

    if (group.size() > 1) {
        int np = sum / group.size();
        for (auto& p : group) {
            a[p.first][p.second] = np;
        }
        return group;
    }
    return {};
}

int main() {
    cin >> N >> L >> R;
    a.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    int days = 0;

    while (true) {
        v.assign(N, vector<bool>(N, false));
        bool move = false;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!v[i][j]) {
                    auto res = bfs(i, j);
                    if (!res.empty()) move = true;
                }
            }
        }

        if (!move) break;
        days++;
    }

    cout << days << endl;
    return 0;
}
