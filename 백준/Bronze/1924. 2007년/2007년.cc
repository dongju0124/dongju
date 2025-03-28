#include<iostream>
using namespace std;

int main()
{
	int M, D;
	cin >> M >> D;

	switch (M)
	{
		case 1:
			D = D + 0;
			break;
		case 2:
			D = D + 31;
			break;
		case 3:
			D = D + 31 + 28;
			break;		
		case 4:
			D = D + 31 + 28 + 31;
			break;		
		case 5:
			D = D + 31 + 28 + 31 + 30;
			break;
		case 6:
			D = D + 31 + 28 + 31 + 30 + 31;
			break;
		case 7:
			D = D + 31 + 28 + 31 + 30 + 31 + 30;
			break;		
		case 8:
			D = D + 31 + 28 + 31 + 30 + 31 + 30 + 31;
			break;		
		case 9:
			D = D + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
			break;		
		case 10:
			D = D + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
			break;		
		case 11:
			D = D + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
			break;		
		case 12:
			D = D + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
			break;
		default:
			break;
	}

	switch (D % 7)
	{
	case 1:
		cout << "MON";
		break;	
	case 2:
		cout << "TUE";
		break;	
	case 3:
		cout << "WED";
		break;	
	case 4:
		cout << "THU";
		break;	
	case 5:
		cout << "FRI";
		break;	
	case 6:
		cout << "SAT";
		break;	
	case 0:
		cout << "SUN";
		break;	
	default:
		break;
	}
}