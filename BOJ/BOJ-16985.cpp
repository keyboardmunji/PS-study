#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int cube[7][7][7], ans = 126;
int board[4][7][7][7];
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = {0,0,1,0,-1,0};
int dz[6] = { 0,0,0,1,0,-1 };

int bfs()
{
	queue<tuple<int,int,int>> q;
	if (cube[1][1][1] == 0 || cube[5][5][5] == 0) return 126;
	int vis[6][6][6] = { 0, };
	q.push({ 1,1,1 });
	vis[1][1][1] = 1;
	while (!q.empty())
	{
		int x, y, z;
		tie(x, y, z) = q.front();q.pop();
		for (int j = 0;j < 6;j++)
		{
			int x1 = x + dx[j];
			int y1 = y + dy[j];
			int z1 = z + dz[j];

			if (x < 1 || x > 5 || y < 1 || y > 5 || z < 1 || z > 5) continue;
			if (vis[x1][y1][z1] || cube[x1][y1][z1] == 0) continue;
			vis[x1][y1][z1] = vis[x][y][z] + 1;
			if (x1 == 5 && y1 == 5 && z1 == 5)
				return vis[x1][y1][z1];
			q.push({ x1,y1,z1 });
		}
	}
	return 126;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	for (int i = 1;i <= 5;i++)
	{
		for (int j = 1;j <= 5;j++)
			for (int k = 1;k <= 5;k++)
				cin >> board[0][i][j][k];
			
		for (int j = 1;j <= 5;j++)
			for (int k = 1;k <= 5;k++)
				board[1][i][j][k] = board[0][i][k][6 - j];
		for (int j = 1;j <= 5;j++)
			for (int k = 1;k <= 5;k++)
				board[2][i][j][k] = board[1][i][k][6 - j];
		for (int j = 1;j <= 5;j++)
			for (int k = 1;k <= 5;k++)
				board[3][i][j][k] = board[2][i][k][6 - j];
	}
	int order[5] = { 1,2,3,4,5 };
	do {
		for (int i = 0;i < 1024;i++)
		{
			int brute = i;
			for (int j = 1;j <= 5;j++)
			{
				int dir = brute % 4;
				for (int b = 1; b <= 5;b++)
					for (int c = 1; c <= 5;c++)
						cube[j][b][c] = board[dir][order[j-1]][b][c];
				brute /= 4;
			}
			ans = min(ans,bfs());
		}
	} while (next_permutation(order, order + 5));
	if (ans == 126)
		ans = 0;
	cout << ans - 1;
	return 0;
}
