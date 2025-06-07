#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {

    string word;
    cin >> word;

    string result = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

    for (int i = 1; i < word.size() - 1; i++) {
        for (int j = i + 1; j < word.size(); j++) {
            string a = word.substr(0, i);
            string b = word.substr(i, j - i);
            string c = word.substr(j);

            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());

            string combined = a + b + c;
            if (combined < result) {
                result = combined;
            }
        }
    }

    cout << result << endl;
    return 0;
}