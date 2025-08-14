#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    // 뒤에서부터 한 자리씩 더하기
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        
        if (i >= 0) {
            sum += a[i] - '0';  // 문자를 숫자로 변환
            i--;
        }
        
        if (j >= 0) {
            sum += b[j] - '0';  // 문자를 숫자로 변환
            j--;
        }
        
        result = char(sum % 2 + '0') + result;  // 현재 자리 결과를 앞에 추가
        carry = sum / 2;  // 올림 계산
    }
    
    // 결과가 0인 경우를 제외하고 앞의 0 제거
    int start = 0;
    while (start < result.length() - 1 && result[start] == '0') {
        start++;
    }
    
    return result.substr(start);
}

int main() {
    string a, b;
    cin >> a >> b;
    
    cout << addBinary(a, b) << endl;
    
    return 0;
}