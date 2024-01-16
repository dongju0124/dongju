#include<iostream>
#include<math.h>
#include<string>

using namespace std;
 
int A, P;

int num[7];
int dp[236196];
int order[236196];
bool visited[236196];

void find_num(int cnt, int N)
{
	int next_N = 0;
	if (visited[N] == true )
	{
		cout << order[N]-1;
		return;
	}

	order[N] = cnt;
	visited[N] = true;

	while (N)
	{
		next_N += pow(N % 10, P);;
		N /= 10;
	}


	find_num(++cnt, next_N);

}

int main() {


	cin >> A >> P;

	dp[1] = A;

	find_num(1, dp[1]);
}