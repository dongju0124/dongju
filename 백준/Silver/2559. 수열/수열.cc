#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> temperatures(N);
    for (int i = 0; i < N; ++i) {
        cin >> temperatures[i];
    }

    int maxSum = 0;
    int currentSum = 0;

    // 초기 K일의 합 구하기
    for (int i = 0; i < K; ++i) {
        currentSum += temperatures[i];
    }
    maxSum = currentSum;

    // 슬라이딩 윈도우를 이용하여 최대 합 구하기
    for (int i = K; i < N; ++i) {
        currentSum += temperatures[i] - temperatures[i - K];
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}
