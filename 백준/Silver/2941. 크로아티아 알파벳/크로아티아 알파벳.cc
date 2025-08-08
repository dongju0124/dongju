#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string word;

	cin >> word;
	int cnt = 0;
	for (int i = 0; i < word.size(); i++)
	{
		 
		if (word[i] == 'd') {
			if (i + 2 < word.size() && word[i + 1] == 'z' && word[i + 2] == '=') {
				cnt++;
				i += 2;
				continue;
			}
			if (i + 1 < word.size() && word[i + 1] == '-') {
				cnt++;
				i += 1;
				continue;
			}
			cnt++;
			continue;
		}

		if (word[i] == 'c')
		{
			if (i + 1 < word.size() && word[i + 1] == '-' || word[i + 1] == '=')
			{
				i++;
				cnt++;
				continue;
			}
			cnt++;
			continue;
		}

		if (word[i] == 'l')
		{
			if (i + 1 < word.size() && word[i + 1] == 'j')
			{
				i++;
				cnt++;
				continue;
			}
			cnt++;
			continue;
		}		
		
		if (word[i] == 'n')
		{
			if (i + 1 < word.size() && word[i + 1] == 'j')
			{
				i++;
				cnt++;
				continue;
			}
			cnt++;
			continue;
		}
		
		if (word[i] =='z' || word[i] == 's')
		{
			if (i + 1 < word.size() && word[i + 1] == '=')
			{
				i++;
				cnt++;
				continue;
			}
			cnt++;
			continue;
		}

		cnt++;
	}

	cout << cnt;
};