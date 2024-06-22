#include <iostream>
#include <cmath>
using namespace std;

int minOperations(int x, int y) {
    int distance = y - x;
    int max_k = sqrt(distance); // max_k는 거리의 제곱근을 반올림한 값입니다.

    // max_k를 기준으로 이동 거리 계산
    if (max_k * max_k == distance) {
        return 2 * max_k - 1;
    }
    else if (max_k * max_k < distance && distance <= max_k * (max_k + 1)) {
        return 2 * max_k;
    }
    else {
        return 2 * max_k + 1;
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int x, y;
        cin >> x >> y;
        cout << minOperations(x, y) << endl;
    }

    return 0;
}
