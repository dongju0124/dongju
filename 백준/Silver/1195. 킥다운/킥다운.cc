#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string gear1, gear2;
    cin >> gear1 >> gear2;

    if (gear1.size() < gear2.size()) {
        swap(gear1, gear2);
    }

    int n = gear1.size();
    int m = gear2.size();

    int min_width = n + m;

    // shift: gear2가 gear1의 어디에서 시작할지를 의미
    for (int shift = -m + 1; shift < n; shift++) {
        bool check = true;

        for (int i = 0; i < m; i++) {
            int j = i + shift;
            if (j >= 0 && j < n) {
                if (gear1[j] == '2' && gear2[i] == '2') 
                {
                    check = false;
                    break;
                }
            }
        }

        if (check) {
            int left = min(0, shift);
            int right = max(n, shift + m);
            int width = right - left;
            min_width = min(min_width, width);
        }
    }

    cout << min_width << endl;
    return 0;
}
