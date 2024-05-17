#include <iostream>
using namespace std;

void hanoi(int n, int from, int to, int by)
{
    if (n == 1)
        cout << "\n" << from << ' ' << to;
    else
    {
        hanoi(n - 1, from, by, to);
        cout << "\n" << from << ' ' << to;
        hanoi(n - 1, by, to, from);
    }
}
int main() {
    int num;
    cin >> num;
    cout << (1 << num) - 1;
    hanoi(num, 1, 3, 2);
}