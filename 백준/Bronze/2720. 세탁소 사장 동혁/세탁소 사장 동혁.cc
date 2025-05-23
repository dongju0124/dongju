#include<iostream>
using namespace std;

int T;
int Q, D, N, P;//Quarter(25), Dime(10), Nickel(5), Penny(1)

int main()
{
	cin >> T;

	while (T--)
	{
		Q = 0; D = 0; N = 0; P = 0;
		int pay;
		cin >> pay;

		if (pay >= 25)
		{
			Q = pay / 25;
			pay %= 25;
		}
		 
		if (pay >= 10)
		{
			D = pay / 10;
			pay %= 10;
		}
		
		if( pay >= 5)
		{
			N = pay / 5;
			pay %= 5;
		}
		
		P = pay;


		cout << Q << " " << D << " " << N << " " << P << "\n";
	}


}