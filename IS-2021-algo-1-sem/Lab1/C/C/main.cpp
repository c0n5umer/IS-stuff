#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) 
{
	int h, w;

	freopen("turtle.in", "r", stdin);
	freopen("turtle.out", "w", stdout);
	cin >> h >> w;
	vector <vector <int>> field(h, vector <int>(w));
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> field[i][j];
	for (int i = h - 2; i >= 0; i--)
		field[i][0] = field[i][0] + field[i + 1][0];
	for (int j = 1; j < w; j++)
		field[h - 1][j] = field[h - 1][j] + field[h - 1][j - 1];
	for (int i = h - 2; i >= 0; i--)
		for (int j = 1; j < w; j++)
			field[i][j] = max(field[i + 1][j], field[i][j - 1]) + field[i][j];
	cout << field[0][w - 1];
	return 0;
}