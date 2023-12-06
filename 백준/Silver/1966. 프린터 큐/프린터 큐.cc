#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq;

        for (int i = 0; i < n; ++i) {
            int priority;
            cin >> priority;
            q.push({ i, priority });
            pq.push(priority);
        }

        int printOrder = 0;

        while (!q.empty()) {
            int currentDoc = q.front().first;
            int currentPriority = q.front().second;
            q.pop();

            if (currentPriority == pq.top()) {
                pq.pop();
                printOrder++;

                if (currentDoc == m) {
                    cout << printOrder << endl;
                    break;
                }
            }
            else {
                q.push({ currentDoc, currentPriority });
            }
        }
    }

    return 0;
}
