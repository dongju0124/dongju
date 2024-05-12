#include <iostream>
#include <vector>

using namespace std;

long long Min, Max;
vector<bool> isSquare;

// 에라토스테네스의 체를 응용하여 제곱ㄴㄴ수의 개수를 찾는 함수
long long countNonsquares(long long Min, long long Max) {
    long long count = Max - Min + 1;
    isSquare.assign(count, false);

    // 주어진 범위 내의 모든 제곱수를 체크
    for (long long i = 2; i * i <= Max; ++i) {
        long long start = Min / (i * i);
        if (Min % (i * i) != 0) 
            start++;

        for (long long j = start; i * i * j <= Max; ++j) {
            isSquare[i * i * j - Min] = true;
        }
    }

    // 제곱ㄴㄴ수의 개수를 세기
    long long nonsquareCount = 0;
    for (bool square : isSquare) {
        if (!square) 
            nonsquareCount++;
    }

    return nonsquareCount;
}

int main() {
    cin >> Min >> Max;
    cout << countNonsquares(Min, Max) << endl;
    return 0;
}