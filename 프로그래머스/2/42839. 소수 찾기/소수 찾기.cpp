#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    sort(numbers.begin(), numbers.end());
    vector<int> nums;
    
    do {
        for (int i = 1; i <= numbers.size(); ++i) {
            int num = stoi(numbers.substr(0, i));
            if (find(nums.begin(), nums.end(), num) == nums.end()) {
                nums.push_back(num);
                if (isPrime(num)) ++answer;
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    return answer;
}
