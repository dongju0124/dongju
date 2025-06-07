#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    vector<int> dp(2000, 100000);

    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        int cost = arr[i].first;
        int customer = arr[i].second;

        for (int j = customer; j < 2000; j++) {
            dp[j] = min(dp[j], dp[j - customer] + cost);
        }
    }

    int answer = 100000;
    for (int i = C; i < 2000; i++) {
        answer = min(answer, dp[i]);
    }

    cout << answer << endl;
    return 0;
}