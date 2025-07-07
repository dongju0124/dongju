#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char decode_word(const string& word) {
    int sum = 0;
    for (char c : word) {
        sum += c - 'a';
    }
    int val = sum % 27;
    if (val == 26)
        return ' ';
    else
        return 'a' + val;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int t = 0; t < T; ++t) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;
        string result;

        while (ss >> word) {
            result += decode_word(word);
        }

        cout << result << '\n';
    }

    return 0;
}
