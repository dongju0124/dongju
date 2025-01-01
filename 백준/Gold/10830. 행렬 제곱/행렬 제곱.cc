#include <iostream>
#include <vector>

using namespace std;

using Matrix = vector<vector<int>>;

// 행렬 곱셈 함수
Matrix multiplyMatrix(const Matrix& a, const Matrix& b, int n) {
    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % 1000;
            }
        }
    }
    return result;
}

// 행렬 거듭제곱 함수 (분할 정복)
Matrix matrixPower(Matrix a, long long b, int n) {
    Matrix result(n, vector<int>(n, 0));
    // 단위 행렬 초기화
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }

    while (b > 0) {
        if (b % 2 == 1) {
            result = multiplyMatrix(result, a, n);
        }
        a = multiplyMatrix(a, a, n);
        b /= 2;
    }

    return result;
}

int main() {
    int n;
    long long b;
    cin >> n >> b;

    Matrix matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    Matrix result = matrixPower(matrix, b, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
