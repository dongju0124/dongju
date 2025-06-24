#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) 
        cin >> A[i];

    vector<int> lis;           
    vector<int> pos(N);       
    vector<int> prev(N, -1);   

    for (int i = 0; i < N; i++) {
        int value = A[i];

        int idx = lower_bound(lis.begin(), lis.end(), value) - lis.begin();

        if (idx == lis.size()) {
            lis.push_back(value);
        }
        else {
            lis[idx] = value;
        }

        pos[i] = idx;
        if (idx != 0) {
            for (int j = i - 1; j >= 0; j--)
            {
                if (pos[j] == idx - 1 && A[j] < A[i]) 
                {
                    prev[i] = j;
                    break;
                }
            }
        }
    }

    int lis_len = lis.size();
    int lis_end = -1;
    for (int i = N - 1; i >= 0; i--) 
    {
        if (pos[i] == lis_len - 1) {
            lis_end = i;
            break;
        }
    }

    vector<int> result;
    while (lis_end != -1) {
        result.push_back(A[lis_end]);
        lis_end = prev[lis_end];
    }

    reverse(result.begin(), result.end());

    cout << lis_len << "\n";
    for (int x : result) cout << x << " ";

    return 0;
}
