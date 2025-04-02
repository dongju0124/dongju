#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T; 
    cin >> T;
    for (int case_num = 1; case_num <= T; ++case_num) {
        int N;
        string S;
        cin >> N >> S;

        vector<int> result(N, 1);

        for (int i = 1; i < N; ++i) {
            if (S[i] > S[i - 1]) {
                result[i] = result[i - 1] + 1;
            }
            else {
                result[i] = 1;
            }
        }

        cout << "Case #" << case_num << ": ";
        for (int i = 0; i < N; ++i) {
            cout << result[i];
            if (i != N - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
