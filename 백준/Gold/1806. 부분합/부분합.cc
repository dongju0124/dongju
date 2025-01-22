#include<iostream>
#include<vector>
using namespace std;

long long N, S;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N >> S;
	vector<int> Num(N);

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> Num[i];
	}

    int minLength = N + 1;
    int start = 0, end = 0, currentSum = 0;

    while (end < N) {
        currentSum += Num[end++]; 

        while (currentSum >= S) {
            minLength = min(minLength, end - start);
            currentSum -= Num[start++];
        }
    }

    if (minLength == N + 1) {
        cout << 0 << endl; 
    }
    else {
        cout << minLength << endl;
    }

    return 0;
}