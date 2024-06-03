#include <iostream>
#include <stack>
#include <string>
using namespace std;

void processKeystrokes(string keystrokes) {
    stack<char> leftStack, rightStack;

    for (char ch : keystrokes) {
        if (ch == '-') {
            // 백스페이스 처리
            if (!leftStack.empty()) {
                leftStack.pop();
            }
        }
        else if (ch == '<') {
            // 커서를 왼쪽으로 이동
            if (!leftStack.empty()) {
                rightStack.push(leftStack.top());
                leftStack.pop();
            }
        }
        else if (ch == '>') {
            // 커서를 오른쪽으로 이동
            if (!rightStack.empty()) {
                leftStack.push(rightStack.top());
                rightStack.pop();
            }
        }
        else {
            // 문자 입력 처리
            leftStack.push(ch);
        }
    }

    // 결과 생성
    string result;
    while (!leftStack.empty()) {
        rightStack.push(leftStack.top());
        leftStack.pop();
    }
    while (!rightStack.empty()) {
        result += rightStack.top();
        rightStack.pop();
    }

    cout << result << endl;
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); // 버퍼 비우기

    while (testCases--) {
        string keystrokes;
        getline(cin, keystrokes);
        processKeystrokes(keystrokes);
    }

    return 0;
}
