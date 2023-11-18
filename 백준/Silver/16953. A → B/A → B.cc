#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int count = 0;

    while (B > A) {
        if (B % 10 == 1) {
            B /= 10;
        }
        else if (B % 2 == 0) {
            B /= 2;
        }
        else {
            break;
        }
        count++;
    }

    if (B == A) {
        cout << count + 1 << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
