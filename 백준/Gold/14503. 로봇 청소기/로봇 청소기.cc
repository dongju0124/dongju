#include<iostream>
#include<algorithm>
using namespace std;

struct robot 
{
	int r;
	int c;
	int d;
};

robot Robot;
int N, M;
int map[51][51];
int clean = 0;
int dy[4] = { -1, 0, 1, 0 };  // 북 동 남 서
int dx[4] = { 0, 1, 0, -1 };

void rotate(int n)
{
	Robot.d = (Robot.d + 3) % 4;
}

void cleaning()
{
	while (true)
	{
		if (map[Robot.r][Robot.c] == 0)
		{
			map[Robot.r][Robot.c] = -1;
			clean++;
		}

		bool moved = false;

		for (int i = 0; i < 4; i++)
		{
			rotate(Robot.d);
			int ny = Robot.r + dy[Robot.d];
			int nx = Robot.c + dx[Robot.d];

			if (map[ny][nx] == 0)
			{
				Robot.r = ny;
				Robot.c = nx;
				moved = true;
				break;
			}
		}

		if (moved) 
			continue; 

		int backDir = (Robot.d + 2) % 4;
		int ny = Robot.r + dy[backDir];
		int nx = Robot.c + dx[backDir];

		if (map[ny][nx] == 1) 
			break;

		Robot.r = ny;
		Robot.c = nx;
	}
}

int main()
{
	cin >> N >> M;
	cin >> Robot.r >> Robot.c >> Robot.d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	cleaning();
	cout << clean << '\n';
}