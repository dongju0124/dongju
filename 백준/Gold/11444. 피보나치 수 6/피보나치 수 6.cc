#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

// 행렬을 곱하는 함수
vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
    int n = A.size();
    vector<vector<long long>> result(n, vector<long long>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] += (A[i][k] * B[k][j]) % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

// 행렬을 거듭제곱하는 함수
vector<vector<long long>> matrixPower(const vector<vector<long long>>& M, long long exponent) {
    if (exponent == 1)
        return M;
    if (exponent % 2 == 0) {
        vector<vector<long long>> half = matrixPower(M, exponent / 2);
        return matrixMultiply(half, half);
    }
    else {
        vector<vector<long long>> half = matrixPower(M, exponent / 2);
        return matrixMultiply(matrixMultiply(half, half), M);
    }
}

// n번째 피보나치 수를 계산하는 함수
long long fibonacci(long long n) {
    if (n <= 1)
        return n;
    vector<vector<long long>> base = { {1, 1}, {1, 0} };
    vector<vector<long long>> result = matrixPower(base, n - 1);
    return result[0][0];
}

int main() {
    long long n;
    cin >> n;
    cout << fibonacci(n) << endl;
    return 0;
}
