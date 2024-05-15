#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;

    cin >> N;

    vector<int> A(N);
    vector<int> P(N);


    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // 배열 A를 정렬하여 정렬된 배열의 각 요소와 해당 요소의 인덱스를 저장하는 쌍.
    vector<pair<int, int>> sorted_A(N);
    for (int i = 0; i < N; ++i) {
        sorted_A[i] = { A[i], i };
    }

    // 배열 A를 기준으로 비내림차순으로 정렬
    sort(sorted_A.begin(), sorted_A.end());

    for (int i = 0; i < N; ++i) {
        P[sorted_A[i].second] = i;
    }

    for (int i = 0; i < N; ++i) {
        cout << P[i] << " ";
    }

    return 0;
}
