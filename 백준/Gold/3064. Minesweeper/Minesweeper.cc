#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int N;
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
vector<vector<int>> board;

// 8방향 중 유효한 숫자 최소값 반환
int getMine(int x, int y) {
    int m = INT_MAX;
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (board[nx][ny] >= 0) {
            m = min(m, board[nx][ny]);
        }
    }
    return m;
}

// 지뢰 근처의 숫자 감소
void removeMine(int x, int y) {
    for (int dir = 0; dir < 8; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (board[nx][ny] >= 0) {
            board[nx][ny]--;
        }
    }
}

// 메인 계산 함수
int countMines() {
    int cnt = 0;
    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < N - 1; j++) {
            int m = getMine(i, j);
            if (m > 0) {
                cnt++;
                removeMine(i, j);
            }
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {

        cin >> N;

        board.assign(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++)
        {
            string S;
            cin >> S;
            for (int j = 0; j < N; j++)
            {
                if (S[j] == '#')
                {
                    board[i][j] = -1;
                }
                else
                {
                    board[i][j] = S[j] - '0';
                }
            }
        }

        cout << countMines() << "\n";

    }
    return 0;
}