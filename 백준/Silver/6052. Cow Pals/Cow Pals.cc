#include <iostream>
using namespace std;

int func(int n) {
    int sum = 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) { 
                sum += n / i;
            }
        }
    }

    return sum;
}

int main() {
    int S;
    cin >> S;

    for (int i = S; ; i++) {
        int sumI = func(i);

        if (sumI == i) {
            continue;
        }

        int sumOfSumI = func(sumI);

        if (sumOfSumI == i) {
            cout << i << " " << sumI << endl;
            return 0;
        }
    }

    return 0;
}