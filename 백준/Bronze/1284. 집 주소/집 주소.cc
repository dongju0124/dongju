#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    while (cin >> s && s != "0") {
        int width = 2; // 양쪽 경계 여백 1cm씩
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') width += 2;
            else if (s[i] == '0') width += 4;
            else width += 3;
            if (i != s.size() - 1) width += 1; // 숫자 사이 여백
        }
        cout << width << '\n';
    }
    return 0;
}