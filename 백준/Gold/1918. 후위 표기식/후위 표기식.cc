#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 연산자의 우선순위를 반환하는 함수
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (char c : infix) {
        // 피연산자(알파벳)인 경우 결과 문자열에 추가
        if (isalpha(c)) {
            postfix += c;
        }
        // '('인 경우 스택에 추가
        else if (c == '(') {
            s.push(c);
        }
        // ')'인 경우 '('를 만날 때까지 스택의 연산자를 결과 문자열에 추가
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // '(' 제거
        }
        // 연산자인 경우
        else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // 스택에 남아 있는 모든 연산자를 결과 문자열에 추가
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cin >> infix;
    string postfix = infixToPostfix(infix);

    cout << postfix << endl;

    return 0;
}
