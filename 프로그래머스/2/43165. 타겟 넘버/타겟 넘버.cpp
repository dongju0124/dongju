#include <string>
#include <vector>

using namespace std;




void dfs(vector<int> numbers, int target, int now, int cnt, int& answer)
{
    if (cnt == numbers.size()){
        if(target == now) answer ++;
        return;
    }
    
    dfs(numbers, target, now + numbers[cnt], cnt + 1, answer);  
    dfs(numbers, target, now - numbers[cnt], cnt + 1, answer);

}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}