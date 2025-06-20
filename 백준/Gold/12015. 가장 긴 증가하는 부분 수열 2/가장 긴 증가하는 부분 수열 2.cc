#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& lis, int target) {
    int left = 0;
    int right = lis.size() - 1;
    int result = lis.size(); 

    while (left <= right) {
        int mid = (left + right) / 2;
        if (lis[mid] >= target) {
            result = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> lis;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    lis.push_back(A[0]);

    for (int i = 1; i < N; i++) {
        if (A[i] > lis.back()) {
            lis.push_back(A[i]);
        }
        else {
            int idx = binarySearch(lis, A[i]);
            lis[idx] = A[i];
        }
    }

    cout << lis.size() << "\n";

    return 0;
}
