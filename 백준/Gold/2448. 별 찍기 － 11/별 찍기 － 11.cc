#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  재귀
void drawStar(vector<string>& pattern, int size, int x, int y) {
    if (size == 3) {
        // 별 그리기
        pattern[y][x] = '*';
        pattern[y + 1][x - 1] = '*';
        pattern[y + 1][x + 1] = '*';
        pattern[y + 2][x - 2] = '*';
        pattern[y + 2][x - 1] = '*';
        pattern[y + 2][x] = '*';
        pattern[y + 2][x + 1] = '*';
        pattern[y + 2][x + 2] = '*';
        return;
    }

    int newSize = size / 2; // 삼각형 쪼개기
    drawStar(pattern, newSize, x, y); // 위 삼각형
    drawStar(pattern, newSize, x - newSize, y + newSize); // 좌하단
    drawStar(pattern, newSize, x + newSize, y + newSize); // 우하단
}

int main() {
    int N;
    cin >> N;

    vector<string> pattern(N, string(2 * N - 1, ' '));

    drawStar(pattern, N, N - 1, 0);

    for (const string& line : pattern) {
        cout << line << "\n";
    }

    return 0;
}
