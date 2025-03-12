#include <iostream>

using namespace std;

int main() {
    int N, num, cnt = 0;
    cin >> N;
    num = N;

    do {
        num = (num % 10) * 10 + (num / 10 + num % 10) % 10;
        cnt++;
    } while (num != N);

    cout << cnt;
    return 0;
}
