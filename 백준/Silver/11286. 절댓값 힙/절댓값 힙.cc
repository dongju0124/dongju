#include <iostream>
#include <queue>
#include <functional> // greater 헤더 파일

using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minAbsHeap;

    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;

        if (x != 0) {
            minAbsHeap.push({ abs(x), x });
        }
        else {
            if (!minAbsHeap.empty()) {
                cout << minAbsHeap.top().second << '\n';
                minAbsHeap.pop();
            }
            else {
                cout << "0\n";
            }
        }
    }

    return 0;
}
