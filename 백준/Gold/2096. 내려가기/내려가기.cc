#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;

int maxPrev[3];
int minPrev[3];
int maxCur[3];
int minCur[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		maxCur[0] = a + max(maxPrev[0], maxPrev[1]);
		maxCur[1] = b + max({maxPrev[0], maxPrev[1], maxPrev[2]});
		maxCur[2] = c + max(maxPrev[1], maxPrev[2]);

		minCur[0] = a + min(minPrev[0], minPrev[1]);
		minCur[1] = b + min({minPrev[0], minPrev[1], minPrev[2]});
		minCur[2] = c + min(minPrev[1], minPrev[2]);

		for (int j = 0; j < 3; j++)
		{
			maxPrev[j] = maxCur[j];
			minPrev[j] = minCur[j];
		}
	}

	cout << max({ maxCur[0], maxCur[1], maxCur[2] }) << " " << min({ minCur[0], minCur[1], minCur[2] });
	
}