#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M; 
    cin >> N >> M;

    vector<int> prices(M);
    for (int i = 0; i < M; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end());

    int maxProfit = 0;  
    int bestPrice = 0;  

    for (int i = 0; i < M; i++) {
        int currentPrice = prices[i];
        int customers = M - i;
        int possibleSales = min(N, customers);

        int profit = currentPrice * possibleSales;

        if (profit >= maxProfit) {
            maxProfit = profit;
            bestPrice = currentPrice;
        }
    }

    cout << bestPrice << " " << maxProfit << "\n";

    return 0;
}