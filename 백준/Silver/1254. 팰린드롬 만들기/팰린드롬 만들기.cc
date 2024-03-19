#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;

    string reversedS = S;
    reverse(reversedS.begin(), reversedS.end());

    // S의 뒤에 S를 뒤집은 문자열(reversedS)에서 공통된 팰린드롬을 찾는다.
    // 공통된 팰린드롬을 찾는 방법은 S와 reversedS의 부분 문자열을 차례로 비교하면서 공통된 부분을 찾는 것이다.
    // 공통된 팰린드롬은 S와 reversedS의 접두사와 접미사가 일치하는 최대 길이를 의미한다.
    int commonPrefixSuffixLength = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S.substr(i) == reversedS.substr(0, S.length() - i)) {
            commonPrefixSuffixLength = S.length() - i;
            break;
        }
    }

    // S의 길이에 reversedS와의 공통된 팰린드롬 길이를 더하면 가장 짧은 팰린드롬의 길이가 된다.
    int shortestPalindromeLength = S.length() * 2 - commonPrefixSuffixLength;
    cout << shortestPalindromeLength << endl;

    return 0;
}
