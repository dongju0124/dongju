#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 행성계
struct Planet {
    int cx, cy, r;
};

vector<Planet> planets;
int T, startX, startY, endX, endY, n;

// 점이 행성계 내에 있는지 확인하는 함수
bool isInside(int x, int y, Planet& p) {
    int dx = x - p.cx;
    int dy = y - p.cy;
    return dx * dx + dy * dy < p.r * p.r;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> startX >> startY >> endX >> endY;
        cin >> n;

        planets.clear();
        planets.resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> planets[i].cx >> planets[i].cy >> planets[i].r;
        }

        int count = 0;

        // 출발점과 도착점이 각각 행성계 안에 있는지 확인
        for (int i = 0; i < n; ++i) {
            bool startInside = isInside(startX, startY, planets[i]);
            bool endInside = isInside(endX, endY, planets[i]);

            // 한 점만 행성계 내에 있는 경우 카운트 증가
            if (startInside != endInside) {
                ++count;
            }
        }

        cout << count << endl;
    }
    return 0;
}
