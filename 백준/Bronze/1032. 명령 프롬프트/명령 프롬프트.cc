#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> files(N);
    for (int i = 0; i < N; i++) {
        cin >> files[i];
    }

    int length = files[0].size();
    string pattern = files[0];  // 첫 번째 파일명을 기준으로 초기 패턴 설정

    // 모든 파일의 같은 위치 문자를 비교
    for (int i = 0; i < length; i++) {
        for (int j = 1; j < N; j++) {
            if (files[j][i] != files[0][i]) {
                pattern[i] = '?';  //다르면 ?로 변경
                break;
            }
        }
    }

    cout << pattern << endl;
    return 0;
}
