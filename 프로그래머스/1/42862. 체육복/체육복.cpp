#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> students(n + 1, 1); // n+1개의 학생을 가정하고 모두 1개의 체육복을 가진 것으로 초기화
    
    // 도난당한 학생들의 체육복 수를 감소시킴
    for(int l : lost)
        students[l]--;
    
    // 여벌의 체육복을 가져온 학생들의 체육복 수를 증가시킴
    for(int r : reserve)
        students[r]++;
    
    // 체육복을 빌려줄 수 있는 경우를 확인하며 체육복을 빌려줌
    for(int i = 1; i <= n; i++) { // 1부터 n까지 반복
        if(students[i] == 0) { // 체육복이 없는 경우
            if(students[i-1] == 2) { // 왼쪽 학생이 여벌의 체육복을 가지고 있는 경우
                students[i]++;
                students[i-1]--;
            } else if(i + 1 <= n && students[i+1] == 2) { // 오른쪽 학생이 여벌의 체육복을 가지고 있는 경우
                students[i]++;
                students[i+1]--;
            }
        }
    }
    
    // 수업을 들을 수 있는 학생 수 계산
    int answer = count_if(students.begin() + 1, students.end(), [](int x) { return x > 0; }); // 0번째 학생은 제외하고 계산
    
    return answer;
}
