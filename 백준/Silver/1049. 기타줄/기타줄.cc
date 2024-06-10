#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> packagePrices(M);
    vector<int> singlePrices(M);
    
    for (int i = 0; i < M; ++i) {
        cin >> packagePrices[i] >> singlePrices[i];
    }
    
    // 가장 저렴한 패키지 가격과 낱개 가격을 찾습니다.
    int minPackagePrice = *min_element(packagePrices.begin(), packagePrices.end());
    int minSinglePrice = *min_element(singlePrices.begin(), singlePrices.end());

    // 가장 저렴한 방법을 계산합니다.
    int result = 123456789;
    for (int i = 0; i <= (N / 6) + 1; ++i) {
        int cost = i * minPackagePrice + (N - i * 6 > 0 ? N - i * 6 : 0) * minSinglePrice;
        result = min(result, cost);
    }
    
    cout << result << endl;
    return 0;
}
