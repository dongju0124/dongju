#include <iostream>
using namespace std;
long long small(long long a, long long b)
{
	long long temp, n;

	while (b != 0)
	{
		long long temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}

int main(void)
{
	long long A, B, C, i;
	cin >> A >> B;
	C = small(A, B);

	for (i = 0; i < C; i++)
		cout << 1;

	return 0;
}