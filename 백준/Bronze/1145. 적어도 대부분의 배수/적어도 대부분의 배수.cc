#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers(5);

    for (int i = 0; i < 5; i++) {
        cin >> numbers[i];
    }

    int num = 1;

    while (true) {
        int count = 0;

        for (int i = 0; i < 5; i++) {
            if (num % numbers[i] == 0) {
                count++;
            }
        }

        if (count >= 3) {
            cout << num << endl;
            break;
        }

        num++;
    }

    return 0;
}
