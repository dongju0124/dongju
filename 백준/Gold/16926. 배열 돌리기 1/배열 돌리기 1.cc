#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr;
vector<vector<int>> arrSub;
int N, M, R;

void rotate() {

    for (int r = 0; r < R; r++)
    {
        // 배열을 회전하는 함수
        for (int k = 0; k < min(N, M) / 2; ++k) {
            int dx = k;
            int dy = k;
            // 왼쪽 세로줄 회전
            for (int i = 0; i < N - k - 1 - k; ++i, dy++)//k를 2번 빼는 이유, 안쪽으로 들어갈 수록 2번씩 덜 움직임
                arrSub[dy + 1][dx] = arr[dy][dx];
            // 아래쪽 가로줄 회전
            for (int i = 0; i < M - k - 1 - k; ++i, dx++)
                arrSub[dy][dx + 1] = arr[dy][dx];
            // 오른쪽 세로줄 회전
            for (int i = 0; i < N - k - 1 - k; ++i, dy--)
                arrSub[dy - 1][dx] = arr[dy][dx];
            // 위쪽 가로줄 회전
            for (int i = 0; i < M - k - 1 - k; ++i, dx--)
                arrSub[dy][dx - 1] = arr[dy][dx];
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                arr[i][j] = arrSub[i][j];
            }
        }
    }


   
}

int main() {

    cin >> N >> M >> R;

    arr.resize(N, vector<int>(M));
    arrSub.resize(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];

    rotate();

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
