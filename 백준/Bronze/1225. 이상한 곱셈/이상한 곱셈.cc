#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string A, B;
    cin >> A >> B;
    
    long long result = 0;
    
    for(char a : A) {
        for(char b : B) {
            result += (a - '0') * (b - '0');
        }
    }
    
    cout << result << '\n';
    
    return 0;
}