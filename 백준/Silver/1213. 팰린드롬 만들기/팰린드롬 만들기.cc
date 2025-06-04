#include<iostream>
using namespace std;

string Name;
char alp[27];
bool odd;
char oddChar;
int len;

int main()
{
	cin >> Name;

	len = Name.size();

	for (int i = 0; i < len; i++)
	{
		alp[Name[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alp[i] % 2 != 0 && !odd)
		{
			odd = true;
			oddChar = i + 'A';
		}
		else if (alp[i] % 2 != 0 && odd)
		{
			cout << "I'm Sorry Hansoo";
			return 0;
		}
	}
    string result = "";
    string temp = "";

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < alp[i] / 2; j++)
        {
            result += (char)(i + 'A');
        }
    }

    temp = result;

    if (odd)
    {
        result += oddChar;
    }

    for (int i = temp.length() - 1; i >= 0; i--)
    {
        result += temp[i];
    }

    cout << result;
    return 0;
}