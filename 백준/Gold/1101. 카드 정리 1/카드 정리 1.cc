#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int arr[50][50];
bool used[50]; // 색상 사용 여부

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    int answer = 0;
    bool jokerUsed = false;
    memset(used, false, sizeof(used));

    for (int i = 0; i < N; i++) {
        int colorCount = 0;
        int lastColor = -1;

        for (int j = 0; j < M; j++) {
            if (arr[i][j]) {
                colorCount++;
                lastColor = j;
            }
        }

        if (colorCount == 0)
            continue; 

        if (colorCount == 1) {
            // 색상 하나만 있는데 이미 쓰인 색이면 이동 필요
            if (used[lastColor]) 
                answer++;
            else 
                used[lastColor] = true;
        }
        else {
            if (!jokerUsed) {
                jokerUsed = true;
            }
            else {
                answer++;
            }
        }
    }

    if (!jokerUsed && answer > 0)
        answer--;

    cout << answer << '\n';
    return 0;
}
