#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int countVowels(const string& sentence) {
    int count = 0;
    for (char c : sentence) {
        char lowerC = tolower(c);
        if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || 
            lowerC == 'o' || lowerC == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    string line;
    
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        
        cout << countVowels(line) << endl;
    }
    
    return 0;
}