#include<iostream>
using namespace std;

long long numA, numB;
long long denA, denB;

long long gcd(int a, int b) {
	if (b == 0) 
		return a;
	else 
		return gcd(b, a % b);
}

int main()
{
	cin >> numA >> denA >> numB >> denB;
	
	long long comDen = denA * denB / gcd(denA, denB);
	long long nNum = numA * (comDen / denA) + numB * (comDen / denB);
	long long nDen = comDen;

	long long g = gcd(nNum, nDen);
	nNum /= g;
	nDen /= g;

	cout << nNum << " " << nDen << "\n";
	return 0;
}
