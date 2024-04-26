#include <iostream>
#include <queue>

using namespace std;

int n, m, team1Power = 0, team2Power = 0;
char battlefield[101][101];
bool visited[101][101];

// 상하좌우 이동을 위한 배열
int direction[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

// BFS 함수 정의
void bfs(int row, int col, char team) {
    queue<pair<int, int>> q;
    q.push({ row, col });
    visited[row][col] = true;

    int cnt = 0;
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        cnt++;

        // 상하좌우 이동 확인
        for (int i = 0; i < 4; i++) {
            int nextRow = current.first + direction[i][0];
            int nextCol = current.second + direction[i][1];

            // 범위 체크 및 방문 여부 확인
            if (nextRow >= 1 && nextRow <= m && nextCol >= 1 && nextCol <= n && !visited[nextRow][nextCol] && battlefield[nextRow][nextCol] == team) {
                visited[nextRow][nextCol] = true;
                q.push({ nextRow, nextCol });
            }
        }
    }

    // 해당 팀의 위력 계산
    if (team == 'W')
        team1Power += cnt * cnt;
    else
        team2Power += cnt * cnt;
}

int main(void) {
    cin >> n >> m;

    // 전투터 정보 입력 받기
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> battlefield[i][j];
        }
    }

    // 각 팀의 영역을 BFS로 탐색하여 위력 계산
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j])
                bfs(i, j, battlefield[i][j]);
        }
    }

    // 각 팀의 위력 출력
    cout << team1Power << ' ' << team2Power;
    return 0;
}
