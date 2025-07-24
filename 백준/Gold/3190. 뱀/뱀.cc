#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Snake {
    int time = 0;
    int direction = 0;
    deque<pair<int, int>> body = { {1, 1} }; 
};
Snake snake;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int N, K, L;
bool apple[101][101];
vector<pair<int, char>> perform;

bool visited[101][101];

void turn(char d) {
    if (d == 'D') snake.direction = (snake.direction + 1) % 4;
    else if (d == 'L') snake.direction = (snake.direction + 3) % 4;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        apple[x][y] = true;
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int x;
        char y;
        cin >> x >> y;
        perform.push_back({ x, y });
    }

    visited[1][1] = true;
    int dir_idx = 0;

    while (true) {
        snake.time++;

        int hx = snake.body.front().first; //head x,y
        int hy = snake.body.front().second;
        int nx = hx + dx[snake.direction];
        int ny = hy + dy[snake.direction];

        if (nx < 1 || nx > N || ny < 1 || ny > N) break;

        if (visited[nx][ny]) 
            break;

        snake.body.push_front({ nx, ny });
        visited[nx][ny] = true;

        if (apple[nx][ny]) {
            apple[nx][ny] = false;
        }
        else {
            int tx = snake.body.back().first; // tail x,y
            int ty = snake.body.back().second;
            visited[tx][ty] = false;
            snake.body.pop_back();
        }

        if (dir_idx < L && snake.time == perform[dir_idx].first) {
            turn(perform[dir_idx].second);
            dir_idx++;
        }
    }

    cout << snake.time << endl;
    return 0;
}
