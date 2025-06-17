#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 알파벳 소문자 개수 카운트 배열
    int count[26] = { 0 };

    // 각 선수의 성 입력받고 첫 글자 카운트
    for (int i = 0; i < N; i++) {
        string lastName;
        cin >> lastName;
        count[lastName[0] - 'a']++;
    }

    // 5명 이상인 첫 글자 찾기
    string result = "";
    for (int i = 0; i < 26; i++) {
        if (count[i] >= 5) {
            result += (char)(i + 'a');
        }
    }

    // 결과 출력
    if (result.empty()) {
        cout << "PREDAJA" << "\n";
    }
    else {
        cout << result << "\n";
    }

    return 0;
}