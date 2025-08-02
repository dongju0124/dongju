#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int S1, S2, S3;
    cin >> S1 >> S2 >> S3;
    
    int minSum = 3;
    int maxSum = S1 + S2 + S3;
    
    vector<int> frequency(maxSum + 1, 0);
    
    for (int i = 1; i <= S1; i++) {
        for (int j = 1; j <= S2; j++) {
            for (int k = 1; k <= S3; k++) {
                int sum = i + j + k;
                frequency[sum]++;
            }
        }
    }
    
    int maxFrequency = 0;
    for (int i = minSum; i <= maxSum; i++) {
        maxFrequency = max(maxFrequency, frequency[i]);
    }
    
    for (int i = minSum; i <= maxSum; i++) {
        if (frequency[i] == maxFrequency) {
            cout << i << endl;
            return 0;
        }
    }
    
    return 0;
}