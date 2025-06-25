#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> lis;
    vector<int> prev(N, -1);
    vector<int> lis_idx; 

    for (int i = 0; i < N; i++) {
        int value = A[i];
        int idx = lower_bound(lis.begin(), lis.end(), value) - lis.begin();

        if (idx == lis.size()) 
        {
            lis.push_back(value);
            lis_idx.push_back(i);
        }
        else 
        {
            lis[idx] = value;
            lis_idx[idx] = i;
        }

        if (idx > 0) {
            prev[i] = lis_idx[idx - 1];
        }
    }
    int lis_len = lis.size();

    int lis_end = lis_idx[lis_len - 1];

    vector<int> result;
    int current = lis_end;
    while (current != -1) {
        result.push_back(A[current]);
        current = prev[current];
    }

    reverse(result.begin(), result.end());

    cout << lis_len << "\n";
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i];
        if (i < result.size() - 1) 
            cout << " ";
    }
    cout << "\n";

    return 0;
}