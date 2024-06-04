#include <iostream>
#include <vector>
#include <string>

using namespace std;

int S, P;
string dna;
vector<int> minCount(4);
vector<int> currentCount(4, 0);
int validPasswordCount = 0;

// DNA의 문자를 카운트하기 위한 함수
void addChar(char c) {
    if (c == 'A') currentCount[0]++;
    else if (c == 'C') currentCount[1]++;
    else if (c == 'G') currentCount[2]++;
    else if (c == 'T') currentCount[3]++;
}

void removeChar(char c) {
    if (c == 'A') currentCount[0]--;
    else if (c == 'C') currentCount[1]--;
    else if (c == 'G') currentCount[2]--;
    else if (c == 'T') currentCount[3]--;
}

bool isValid() {
    return currentCount[0] >= minCount[0] &&
        currentCount[1] >= minCount[1] &&
        currentCount[2] >= minCount[2] &&
        currentCount[3] >= minCount[3];
}

int main() {
    cin >> S >> P;
    cin >> dna;
    for (int i = 0; i < 4; ++i) {
        cin >> minCount[i];
    }

    // 처음 P 길이의 윈도우를 설정
    for (int i = 0; i < P; ++i) {
        addChar(dna[i]);
    }

    // 첫 윈도우가 유효한지 검사
    if (isValid()) {
        validPasswordCount++;
    }

    // 슬라이딩 윈도우를 이용해 나머지 부분문자열을 검사
    for (int i = P; i < S; ++i) {
        addChar(dna[i]);
        removeChar(dna[i - P]);
        if (isValid()) {
            validPasswordCount++;
        }
    }

    cout << validPasswordCount << endl;
    return 0;
}
