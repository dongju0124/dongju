#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> num;

void solve(long long n, int lastNum) {
    num.push_back(n);
    for (int i = 0; i < lastNum; i++) 
    {
        solve(n * 10 + i, i);
    }
}

int main() {
    int N;
    cin >> N;

    num.push_back(0);

    for (int i = 1; i <= 9; i++) {
        solve(i, i);
    }

    sort(num.begin(), num.end());

    if (N > num.size()) 
    {
        cout << -1;
    }
    else 
    {
        cout << num[N - 1];
    }

    return 0;
}