#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();

    int minDiff = lenA;

    for (int start = 0; start <= lenB - lenA; start++) {
        int diff = 0;

        for (int i = 0; i < lenA; i++) {
            if (A[i] != B[start + i]) {
                diff++;
            }
        }

        minDiff = min(minDiff, diff);
    }

    cout << minDiff << endl;

    return 0;
}