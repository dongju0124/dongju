#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    int d1, d2;
    int x;

    cin >> d1 >> d2 >> x;

    int D1, D2;

    D1 = max(d1, d2);
    D2 = min(d1, d2);

    double m = 100 - x;
    double v = m / D2;

    m = x;
    v += m / D1;
    cout.precision(10);
    cout << 100 / v;

    return 0;
}
