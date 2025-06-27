#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> straws(N);
    for (int i = 0; i < N; i++) {
        cin >> straws[i];
    }

    sort(straws.begin(), straws.end(), greater<int>());

    int result = -1;
    for (int i = 0; i < N - 2; i++) {
        if (straws[i] < straws[i + 1] + straws[i + 2]) {
            result = straws[i] + straws[i + 1] + straws[i + 2];
            break;
        }
    }

    cout << result << '\n';

    return 0;
}