#include <iostream>
#include <string>
#include <set>
using namespace std;

const int MAX = 1001;
string numbers[MAX];
int N;

bool isUnique(int k) {
    set<string> subNumbers;
    for (int i = 0; i < N; i++) {
        // 뒤에서 k자리만 추출
        string sub = numbers[i].substr(numbers[i].length() - k);
        if (subNumbers.find(sub) != subNumbers.end()) {
            return false;
        }
        subNumbers.insert(sub);
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }
    
    int len = numbers[0].length();
    
    for (int k = 1; k <= len; k++) {
        if (isUnique(k)) {
            cout << k << "\n";
            break;
        }
    }

    return 0;
}