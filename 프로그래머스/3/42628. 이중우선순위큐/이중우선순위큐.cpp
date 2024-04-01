#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int cnt = 0;
    
    for(string op: operations)
    {
        if(!cnt)
        {
            while (!max_heap.empty())
                max_heap.pop();
            while (!min_heap.empty())
                min_heap.pop();
        }
        
        if(op[0]=='I')
        {
            max_heap.push(stoi(op.substr(2)));
            min_heap.push(stoi(op.substr(2)));
            cnt++;
        }
        else{
            if(!cnt) continue;
            
            if(op[2] =='1')
            {
                max_heap.pop();
                cnt--;
            }
            else{
                min_heap.pop();
                cnt--;
            }
        }
    }
    if(cnt){
        answer[0] = max_heap.top();
        answer[1] = min_heap.top();
    }
    
    return answer;
}