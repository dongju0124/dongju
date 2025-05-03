#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	double C;

	double N;
	
	cin >> C;

	while (C--)
	{
		cin >> N;
		vector<double> students;

		int sum = 0;

		for (int i = 0; i < N; i++)
		{
			double temp;
			cin >> temp;
			sum += temp;
			students.push_back(temp);
		}

		sum = sum / N;

		double cnt = 0;

		for (int i = 0; i < N; i++)
		{
			if (students[i] > sum)
				cnt++;
		}
		
		double per = 100*(cnt/N);
		cout << fixed;
		cout.precision(3);
		cout << per << "%" << "\n";
	}
}