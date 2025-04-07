#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> calls(N);
    for (int i = 0; i < N; ++i) {
        cin >> calls[i];
    }

    int y_cost = 0; // 영식 요금
    int m_cost = 0; // 민식 요금

    for (int i = 0; i < N; ++i) {
        y_cost += (calls[i] / 30 + 1) * 10;
        m_cost += (calls[i] / 60 + 1) * 15;
    }

    if (y_cost < m_cost) {
        cout << "Y " << y_cost << endl;
    }
    else if (m_cost < y_cost) {
        cout << "M " << m_cost << endl;
    }
    else {
        cout << "Y M " << y_cost << endl;
    }

    return 0;
}
