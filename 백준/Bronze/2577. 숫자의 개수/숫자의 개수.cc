#include<iostream>
using namespace std;

long long mul;
int A, B, C;
int result[10] = { 0 };

int main() {
	cin >> A >> B >> C;
	mul = A * B * C;

	while (mul>0)
	{
		result[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << result[i] << "\n";
	}
}