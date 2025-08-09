#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int R;
        string S;
        cin >> R >> S;

        string P;
        for (char c : S) {
            for (int i = 0; i < R; i++) {
                P += c;
            }
        }
        cout << P << "\n";
    }

    return 0;
}
