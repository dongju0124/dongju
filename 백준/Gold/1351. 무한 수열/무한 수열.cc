#include<iostream>
#include<unordered_map>
using namespace std;

long long N, P, Q;
unordered_map<long long, long long> map;

long long seq(long long n)
{
	if (n == 0)
		return 1;

	long long ans = map[n];

	if (ans != 0)
		return ans;

	ans = seq(n / P) + seq(n / Q);
	map[n] = ans;

	return ans;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> P >> Q;
	map[0] = 1;

	cout << seq(N);

}