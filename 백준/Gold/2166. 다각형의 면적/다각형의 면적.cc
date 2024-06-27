#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    long long x, y;
};

int main() {
    int N;
    cin >> N;

    vector<Point> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // 신발끈 공식 적용
    long long area = 0;
    for (int i = 0; i < N; ++i) {
        int j = (i + 1) % N;
        area += points[i].x * points[j].y;
        area -= points[i].y * points[j].x;
    }

    // 절대값을 취하고 1/2 곱하기
    area = abs(area);
    double final_area = area / 2.0;

    // 소수점 첫째 자리까지 출력
    cout << fixed << setprecision(1) << final_area << endl;

    return 0;
}
