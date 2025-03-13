#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int count;
    cin >> count;
    
    vector<int> divisors(count);
    for (int i = 0; i < count; i++) {
        cin >> divisors[i];
    }
    
    int min_divisor = *min_element(divisors.begin(), divisors.end());
    int max_divisor = *max_element(divisors.begin(), divisors.end());
    
    int N = min_divisor * max_divisor;
    
    cout << N << endl;
    
    return 0;
}
