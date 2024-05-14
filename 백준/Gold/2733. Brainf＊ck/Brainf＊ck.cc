#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <stack>
using namespace std;

int t;
string info;
vector<char> word(32768);
int point;
string result;
map<int, int> left_right; //[]의 짝을 저장한다([,])순으로 저장
map<int, int> right_left; //[]의 짝을 저장한다(],[)순으로 저장
stack<int> blank;

void Pre()
{
	info.clear();

	for (int i = 0; i < 32768; i++)
		word[i] = 0;

	point = 0;

	result.clear();

	left_right.clear();
	right_left.clear();

	while (!blank.empty())
		blank.pop();
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> t;
	cin.ignore();

	for (int i = 1; i <= t; i++)
	{
		Pre();
		while (1)
		{
			string input;
			getline(cin, input);

			if (input == "end")
				break;

			//주석 뒤는 무시한다
			if (input.find("%") != string::npos)
			{
				int index = input.find("%");

				input = input.substr(0, index);
			}

			info += input;
		}

		for (int j = 0; j < info.size(); j++)
		{
			if (info[j] == '[')
				blank.push(j);

			else if (info[j] == ']')
			{
				if (blank.size() == 0)
				{
					result = "COMPILE ERROR";
					break;
				}

				else //괄호 짝을 저장한다
				{
					int left_b = blank.top();
					blank.pop();
					int right_b = j;

					left_right.insert(make_pair(left_b, right_b));
					right_left.insert(make_pair(right_b, left_b));
				}
			}
		}

		if (blank.size() != 0)
			result = "COMPILE ERROR";

		if (result == "COMPILE ERROR")
		{
			cout << "PROGRAM #" << i << ":" << "\n";
			cout << result << "\n";
			continue;
		}

		for (int j = 0; j < info.size(); j++)
		{
			if (info[j] == '>')
			{
				if (point == 32767)
					point = 0;

				else
					point++;
			}

			else if (info[j] == '<')
			{
				if (point == 0)
					point = 32767;

				else
					point--;
			}

			else if (info[j] == '+')
			{
				if (word[point] == ((1 << 8) - 1))
					word[point] = 0;

				else
					word[point]++;
			}

			else if (info[j] == '-')
			{
				if (word[point] == 0)
					word[point] = ((1 << 8) - 1);

				else
					word[point]--;
			}

			else if (info[j] == '.')
			{
				result += word[point];
			}

			else if (info[j] == '[')
			{
				if (word[point] == 0)
				{
					int next_index = left_right[j];

					j = next_index;
					j--;
				}
			}

			else if (info[j] == ']')
			{

				if (word[point] != 0)
				{
					int next_index = right_left[j];

					j = next_index;
					j--;
				}
			}
		}

		cout << "PROGRAM #" << i << ":" << "\n";
		cout << result << "\n";
	}


	return 0;
}