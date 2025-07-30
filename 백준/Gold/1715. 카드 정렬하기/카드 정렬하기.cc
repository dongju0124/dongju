#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long minCount = 0;
vector<int> num;

int main()
{
    cin >> N;
    num.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    while (num.size() > 1) {
        int first = num[0];
        int second = num[1];
        int sum = first + second;
        minCount += sum;

        num.erase(num.begin());
        num.erase(num.begin());

        auto pos = lower_bound(num.begin(), num.end(), sum);
        num.insert(pos, sum);
    }

    cout << minCount << '\n';
    return 0;
}