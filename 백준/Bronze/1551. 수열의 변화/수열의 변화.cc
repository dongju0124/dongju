#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> split(string input) {
    vector<int> result;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, ',')) {
        result.push_back(stoi(temp));
    }
    return result;
}

int main() {
    int N, K;
    string line;

    cin >> N >> K;
    cin.ignore(); 
    getline(cin, line);

    vector<int> A = split(line);

    for (int k = 0; k < K; ++k) {
        vector<int> next;
        for (int i = 0; i < A.size() - 1; ++i) {
            next.push_back(A[i + 1] - A[i]);
        }
        A = next;
    }

    for (int i = 0; i < A.size(); ++i) {
        cout << A[i];
        if (i != A.size() - 1) cout << ",";
    }
    cout << "\n";

    return 0;
}
