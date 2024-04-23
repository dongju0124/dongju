#include <iostream>
using namespace std;

int T, N, cnt, num, ans;
int constraints[52];

// 주어진 조합이 제약 조건을 만족하는지 확인하는 함수
bool make(int sub) {
    for (int i = 0; i < N; ++i) {
        if ((constraints[i] & sub) == constraints[i]) 
            return false;
    }
    return true;
}

int main() {
    // 입력 받기
    cin >> T >> N;
    for (int i = 0; i < N; ++i) {
        cin >> cnt;
        while (cnt--) {
            cin >> num;
            num--; // 0-based index로 변환
            constraints[i] |= (1 << num); // 해당하는 재료 비트를 1로 설정
        }
    }

    // 가능한 피자의 조합 수 계산
    for (int i = 0; i < (1 << T); ++i) {
        if (make(i))
            ++ans; // 제약 조건을 만족하는 조합인 경우
    }
    // 결과 출력
    cout << ans;

    return 0;
}
