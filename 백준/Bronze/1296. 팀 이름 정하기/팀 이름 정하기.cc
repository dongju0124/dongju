#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// L,O,V,E 개수를 세는 함수
vector<int> countLOVE(const string& str) {
    vector<int> cnt(4, 0);
    for(char c : str) {
        if(c == 'L') cnt[0]++;
        else if(c == 'O') cnt[1]++;
        else if(c == 'V') cnt[2]++;
        else if(c == 'E') cnt[3]++;
    }
    return cnt;
}

// 확률 계산 함수
long long calculateProbability(const vector<int>& total) {
    long long L = total[0], O = total[1], V = total[2], E = total[3];
    return ((L+O) * (L+V) * (L+E) * (O+V) * (O+E) * (V+E)) % 100;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string yeondoo;
    cin >> yeondoo;
    
    int N;
    cin >> N;
    
    vector<string> teams(N);
    string answer;
    long long maxProb = -1;
    
    vector<int> yeondooCnt = countLOVE(yeondoo);
    
    for(int i = 0; i < N; i++) {
        cin >> teams[i];
        
        vector<int> teamCnt = countLOVE(teams[i]);
        
        vector<int> totalCnt(4);
        for(int j = 0; j < 4; j++) {
            totalCnt[j] = yeondooCnt[j] + teamCnt[j];
        }
        
        long long prob = calculateProbability(totalCnt);
        
        if(prob > maxProb || (prob == maxProb && teams[i] < answer)) {
            maxProb = prob;
            answer = teams[i];
        }
    }
    
    cout << answer << '\n';
    
    return 0;
}