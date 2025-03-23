#include<iostream>
using namespace std;

int main() {
    int N, F;
    cin >> N >> F;

    N = N - (N % 100); // 마지막 두 자리 00

    for (int i = 0; i < 100; ++i) {
        if ((N + i) % F == 0) {
            if (i < 10)
                cout << '0' << i << endl; // 한 자리면 앞에 0
            else
                cout << i << endl;
            break;
        }
    }

    return 0;
}
