#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> S(N);

    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }

    // 수열을 정렬
    sort(S.begin(), S.end());

    // 만들 수 있는 가장 작은 수를 추적
    int smallest_missing = 1;

    // 각 수열의 원소를 순회하면서 부분 수열의 합을 체크
    for (int i = 0; i < N; ++i) {
        // 만약 smallest_missing을 만들 수 없다면 종료
        if (S[i] > smallest_missing) {
            break;
        }
        // smallest_missing을 만들 수 있으면 다음 smallest_missing을 갱신
        smallest_missing += S[i];
    }

    cout << smallest_missing << endl;
    return 0;
}
