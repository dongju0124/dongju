#include <iostream>
#include <queue>
using namespace std;

// 좌표를 나타내는 구조체
struct Point {
    int x, y, z;
};

// 전역 변수 선언
int M, N, H;
int boxes[100][100][100];
queue<Point> q;

// 방향을 나타내는 배열 (상, 하, 좌, 우, 앞, 뒤)
int dx[] = { 0, 0, 0, 0, -1, 1 };
int dy[] = { 0, 0, -1, 1, 0, 0 };
int dz[] = { -1, 1, 0, 0, 0, 0 };

// BFS 함수 정의
void bfs() {
    while (!q.empty()) {
        Point current = q.front();
        q.pop();

        for (int dir = 0; dir < 6; ++dir) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];
            int nz = current.z + dz[dir];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H && boxes[nx][ny][nz] == 0) {
                boxes[nx][ny][nz] = boxes[current.x][current.y][current.z] + 1;
                q.push({ nx, ny, nz });
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;

    // 익은 토마토의 좌표를 저장하는 큐
    // 상자 정보 입력 받기
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> boxes[i][j][k];
                if (boxes[i][j][k] == 1) {
                    q.push({ i, j, k });
                }
            }
        }
    }

    // BFS 함수 호출
    bfs();

    // 최소 일수 찾기
    int answer = 0;
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (boxes[i][j][k] == 0) {
                    cout << -1 << endl;
                    return 0;
                }
                answer = max(answer, boxes[i][j][k]);
            }
        }
    }

    cout << answer - 1 << endl;

    return 0;
}
