#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;

        vector<pair<int, int>> applicants; // 서류심사, 면접 성적을 저장하는 pair 벡터

        for (int i = 0; i < N; ++i) {
            int document, interview;
            cin >> document >> interview;
            applicants.push_back(pair<int, int>(document, interview));
        }

        sort(applicants.begin(), applicants.end()); // 서류심사 성적을 기준으로 정렬

        int maxInterviewRank = N + 1; // 초기값을 N+1로 설정하여 모든 지원자보다 면접 순위가 높게 시작
        int count = 0; // 선발된 신입사원의 수를 카운트

        for (int i = 0; i < N; ++i) {
            if (applicants[i].second < maxInterviewRank) {
                // 현재 지원자의 면접 성적이 기존의 최고 면접 성적보다 좋을 경우 선발
                maxInterviewRank = applicants[i].second;
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
