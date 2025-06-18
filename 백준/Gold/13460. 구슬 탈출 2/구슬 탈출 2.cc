#include<iostream>
#include<queue>
using namespace std;

int N, M;
char map[10][10];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool visited[10][10][10][10];
struct Ball {
    int rx, ry, bx, by, depth;
};

pair<int, int> move(int x, int y, int dx, int dy, int& cnt) {
    cnt = 0;
    while (map[x + dx][y + dy] != '#' && map[x][y] != 'O') 
    {
        x += dx;
        y += dy;
        cnt++;
        if (map[x][y] == 'O') 
            break;
    }
    return { x, y };
}

void bfs(pair<int, int> r_start, pair<int, int> b_start) {
    queue<Ball> q;
    q.push({ r_start.first, r_start.second, b_start.first, b_start.second, 0 });
    visited[r_start.first][r_start.second][b_start.first][b_start.second] = true;

    while (!q.empty()) {
        Ball cur = q.front();
            q.pop();

        if (cur.depth >= 10) {
            cout << -1 << endl;
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int rcnt = 0, bcnt = 0;

            pair<int, int> red = move(cur.rx, cur.ry, dx[dir], dy[dir], rcnt);
            int nrx = red.first;
            int nry = red.second;

            pair<int, int> blue = move(cur.bx, cur.by, dx[dir], dy[dir], bcnt);
            int nbx = blue.first;
            int nby = blue.second;

            if (map[nbx][nby] == 'O')
                continue;

            if (map[nrx][nry] == 'O') {
                cout << cur.depth + 1 << endl;
                return;
            }

            //구슬 겹치기 방지(조금 움직인 쪽이 먼저 도착)
            if (nrx == nbx && nry == nby) {
                if (rcnt > bcnt) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                }
                else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }

            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({ nrx, nry, nbx, nby, cur.depth + 1 });
            }
        

        }
    }

    cout << -1 << endl;
}

int main()
{
    cin >> N >> M;

    pair<int, int> r_start, b_start;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'R') 
                r_start = { i, j };
            if (map[i][j] == 'B') 
                b_start = { i, j };
        }
    }

    bfs(r_start, b_start);
}