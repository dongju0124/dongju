#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int ans = 0;
vector <int> A;
vector <int> B;

int main() {

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		A.push_back(k);
	}	
	for (int i = 0; i < N; i++)
	{
		int k;
		cin >> k;
		B.push_back(k);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	for (int i = 0; i < N; i++)
	{
		ans += A[i] * B[i];
	}

	cout << ans;

}