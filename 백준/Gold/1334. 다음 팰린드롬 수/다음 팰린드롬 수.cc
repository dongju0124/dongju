#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAllNines(const string& str) {
    for (char c : str) {
        if (c != '9') {
            return false;
        }
    }
    return true;
}

string getNextPalindrome(string num) {
    int n = num.size();
    string nextPalindrome = num;

    // 주어진 수의 절반을 이용하여 팰린드롬을 만듦
    string firstHalf = num.substr(0, (n + 1) / 2);
    string secondHalf = firstHalf;
    reverse(secondHalf.begin(), secondHalf.end());

    // 팰린드롬을 만들고 입력된 수보다 큰지 확인
    nextPalindrome = firstHalf + (n % 2 == 0 ? secondHalf : secondHalf.substr(1));
    if (nextPalindrome <= num) {
        // 만들어진 팰린드롬이 입력된 수와 같거나 작으면 다음 팰린드롬을 찾기 위해 중간 값을 증가시킴
        int carry = 1;
        for (int i = (n - 1) / 2; i >= 0 && carry; i--) {
            int digit = nextPalindrome[i] - '0' + carry;
            nextPalindrome[i] = digit % 10 + '0';
            carry = digit / 10;
        }
        // 다시 팰린드롬을 만듦
        firstHalf = nextPalindrome.substr(0, (n + 1) / 2);
        secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());
        nextPalindrome = firstHalf + (n % 2 == 0 ? secondHalf : secondHalf.substr(1));
    }
    return nextPalindrome;
}

int main() {
    string N;
    cin >> N;

    if (isAllNines(N)) {
        // 입력된 수가 9로만 이루어져 있는 경우
        for (char& c : N) {
            c = '0';
        }
        N[0] = '1';
        N = N + '1';
        cout << N;
    }
    else {
        // 그렇지 않은 경우
        string result = getNextPalindrome(N);
        cout << result;
    }

    return 0;
}
