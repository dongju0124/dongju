#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits> 
#include <string>
using namespace std;

int R, C;
char grid[51][51];
int water_time[51][51];
bool visited[51][51];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

struct Node { 
    int x, y, t; 
}; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    pair<int, int> S, D;
    queue<pair<int, int>> wq;

    for (int i = 0; i < R; ++i) {
        string row; cin >> row;
        for (int j = 0; j < C; ++j) {
            grid[i][j] = row[j];
            water_time[i][j] = INT_MAX; 
            if (grid[i][j] == 'S') 
                S = make_pair(i, j);
            if (grid[i][j] == 'D') 
                D = make_pair(i, j);
            if (grid[i][j] == '*') 
            {
                wq.push(make_pair(i, j));
                water_time[i][j] = 0;
            }
        }
    }

    // 1) 물 BFS 각 칸에 물 도착 시간 기록
    while (!wq.empty()) {
        pair<int, int> cur = wq.front(); wq.pop();
        int x = cur.first, y = cur.second;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            if (grid[nx][ny] == 'X') 
                continue;
            if (grid[nx][ny] == 'D') 
                continue;
            if (water_time[nx][ny] == INT_MAX) {
                water_time[nx][ny] = water_time[x][y] + 1;
                wq.push(make_pair(nx, ny));
            }
        }
    }

    // 2) 고슴도치 BFS
    queue<Node> q;
    q.push({ S.first, S.second, 0 });
    visited[S.first][S.second] = true;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, t = cur.t;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) 
                continue;
            if (visited[nx][ny])
                continue;
            if (grid[nx][ny] == 'X') 
                continue;

            if (grid[nx][ny] == 'D') {
                cout << (t + 1) << "\n";
                return 0;
            }

            // 물 도착시간 > 내가 도착하는 시간(t+1)
            if (grid[nx][ny] == '.') {
                if (water_time[nx][ny] > t + 1) {
                    visited[nx][ny] = true;
                    q.push({ nx, ny, t + 1 });
                }
            }
        }
    }

    cout << "KAKTUS\n";
    return 0;
}
