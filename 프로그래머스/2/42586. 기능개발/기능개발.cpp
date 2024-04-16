#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days(speeds.size(), 0);
    
    // 각 작업의 진도에 필요한 남은 일수 계산
    for(int i = 0; i < speeds.size(); i++) {
        int days_left = 100 - progresses[i];
        while(days_left > 0) {
            days[i]++;
            days_left -= speeds[i];
        }
    }
    
    // 뒤에 있는 기능이 앞에 있는 기능보다 먼저 완료되는지 확인하여 배포되는 기능의 개수 계산
    for(int i = 0; i < days.size() - 1; i++) {
        if(days[i] > days[i + 1]) {
            days[i + 1] = days[i];
        }
    }
    
    // 배포되는 기능의 개수를 answer 벡터에 저장
    int temp = 1;
    for(int i = 0; i < days.size() - 1; i++) {
        if(days[i] == days[i + 1]) {
            temp++;
        } else {
            answer.push_back(temp);
            temp = 1;
        }
    }
    // 마지막 기능의 배포 개수 저장
    answer.push_back(temp);
    
    return answer;
}
