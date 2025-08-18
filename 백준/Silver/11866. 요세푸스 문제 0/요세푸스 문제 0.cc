#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> q;
    for (int i = 1; i <= N; i++) {
        q.push_back(i);
    }

    vector<int> result;
    int index = 0;

    while (!q.empty()) {
        // K번째 사람의 인덱스 계산
        index = (index + K - 1) % q.size();

        result.push_back(q[index]);
        q.erase(q.begin() + index);

        if (index == q.size()) {
            index = 0;
        }
    }

    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    return 0;
}