#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++) {
        int start_idx = commands[i][0] - 1;
        int end_idx = commands[i][1];
        int k = commands[i][2] - 1;
        
        vector<int> temp(array.begin() + start_idx, array.begin() + end_idx);
        
        sort(temp.begin(), temp.end());
        
        answer.push_back(temp[k]);
    }
    
    return answer;
}