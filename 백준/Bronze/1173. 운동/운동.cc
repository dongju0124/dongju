#include <iostream>
using namespace std;

int N, m, M, T, R;

int main() {
    cin >> N >> m >> M >> T >> R;
    
    if (m + T > M) {
        cout << -1 << endl;
        return 0;
    }
    
    int currentPulse = m;  
    int exerciseTime = 0; 
    int totalTime = 0;     
    
    while (exerciseTime < N) {
        totalTime++;
        
        if (currentPulse + T <= M) {
            currentPulse += T;
            exerciseTime++;
        } else {
            currentPulse -= R;
            if (currentPulse < m) {
                currentPulse = m;
            }
        }
    }
    
    cout << totalTime << endl;
    return 0;
}