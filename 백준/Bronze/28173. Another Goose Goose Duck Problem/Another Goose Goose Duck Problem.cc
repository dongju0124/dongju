#include <iostream>
using namespace std;

typedef long long ll;

ll l, r, b, k;

int main()
{
    cin >> l >> r >> b >> k;

    // l 이상인 b의 배수 중 가장 작은 수 t를 구함
    ll t = (l / b) * b;
    if (t < l)
        t += b;

    // t에 k를 곱한 결과 출력
    cout << k * t << endl;

    return 0;
}
