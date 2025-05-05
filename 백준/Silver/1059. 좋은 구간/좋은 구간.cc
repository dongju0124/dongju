#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> S;

int main()
{
	int L, N;
	
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int temp;
		cin >> temp;

		S.push_back(temp);
	}

	cin >> N;
	for (int i = 0; i < L; i++)
	{
		if (S[i] == N)
		{
			cout << 0;
			return 0;
		};
	}
	sort(S.begin(), S.end());

	int flag;
	int start = 0;
	int end = 1001;
	for (int i = 0; i < L; i++)
	{
		if (S[i] < N) {
			start = S[i];
		}
		if (S[i] > N) {
			end = S[i];
			break;
		}
	}

	int result = (N - start) * (end - N) - 1;

	cout << result;
}