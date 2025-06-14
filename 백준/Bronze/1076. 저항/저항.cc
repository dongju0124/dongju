#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

map<string, long long> m;

string first;
string second;
string third;

void set()
{
	m.insert({ "black",0});
	m.insert({ "brown",1});
	m.insert({ "red",2});
	m.insert({ "orange",3});
	m.insert({ "yellow",4});
	m.insert({ "green",5});
	m.insert({ "blue",6});
	m.insert({ "violet",7});
	m.insert({ "grey",8});
	m.insert({ "white",9});
}

int main()
{
	set();
	cin >> first >> second >> third;

	int mul = 1;

	for (int i = 0; i < m[third]; i++)
	{
		mul = mul * 10;
	}

	cout << (m[first] * 10 + m[second]) * mul;
}