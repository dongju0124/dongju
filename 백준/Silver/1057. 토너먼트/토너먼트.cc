#include <iostream>
using namespace std;

int main() {
    int N, jimin, hansu;
    cin >> N >> jimin >> hansu;

    int round = 0;

    // 서로 대결할 때까지 라운드를 진행합니다.
    while (jimin != hansu) {
        // 현재 라운드의 번호를 증가시킵니다.
        round++;

        // 다음 라운드에서 번호를 다시 매깁니다.
        // (jimin + 1) / 2와 (hansu + 1) / 2는 다음 라운드의 번호가 됩니다.
        jimin = (jimin + 1) / 2;
        hansu = (hansu + 1) / 2;
    }

    // 라운드 번호를 출력합니다.
    cout << round << endl;

    return 0;
}
