#include <iostream>
using namespace std;

int X;

int main() {
    cin >> X;

    int count = 0;
    while (X > 0) 
    {
        if (X % 2 == 1)
            count++;
        X /= 2;
    }

    cout << count << '\n';
    return 0;
}
