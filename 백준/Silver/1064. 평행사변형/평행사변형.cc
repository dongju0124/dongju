#include<iostream>
#include<algorithm>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
	double Xa, Ya, Xb, Yb, Xc, Yc;
	cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc;

	if ((Yb - Ya) * (Xc - Xb) == (Yc - Yb) * (Xb - Xa))
	{
		cout << "-1.0";
		return 0;
	}

	double b_a = sqrt((Xb - Xa) * (Xb - Xa) + (Yb - Ya) * (Yb - Ya));
	double c_a = sqrt((Xc - Xa) * (Xc - Xa) + (Yc - Ya) * (Yc - Ya));
	double c_b = sqrt((Xc - Xb) * (Xc - Xb) + (Yc - Yb) * (Yc - Yb));

	double maxLine = max(b_a * 2 + c_a * 2, max(c_a * 2 + c_b * 2, c_b * 2 + b_a * 2));
	double minLine = min(b_a * 2 + c_a * 2, min(c_a * 2 + c_b * 2, c_b * 2 + b_a * 2));

	cout << fixed << setprecision(9) << maxLine - minLine;
}