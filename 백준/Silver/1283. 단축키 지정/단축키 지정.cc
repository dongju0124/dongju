#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

bool alp[26];

string SetKey(string str) {

    int start = 0;
    for (int i = 0; i < str.length(); i++) {
        if (i == 0 || str[i - 1] == ' ') {  // 단어의 시작
            char c = tolower(str[i]);
            if (c >= 'a' && c <= 'z' && !alp[c - 'a']) {
                alp[c - 'a'] = true;
                return str.substr(0, i) + "[" + str[i] + "]" + str.substr(i + 1);
            }
        }
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            char c = tolower(str[i]);
            if (c >= 'a' && c <= 'z' && !alp[c - 'a']) {
                alp[c - 'a'] = true;
                return str.substr(0, i) + "[" + str[i] + "]" + str.substr(i + 1);
            }
        }
    }

    return str;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();

    vector<string> options(N);
    for (int i = 0; i < N; i++) {
        getline(cin, options[i]);
        options[i] = SetKey(options[i]);
        cout << options[i] << "\n";
    }

    return 0;
}