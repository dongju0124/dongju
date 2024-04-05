#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for(int i=0; i<citations.size(); i++)
    {
        while(citations[i]>=answer && citations.size()-i>= answer)
            answer++;
    }
    return answer-1;
}