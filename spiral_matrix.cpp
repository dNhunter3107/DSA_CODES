
#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
	int m = matrix.size(), n = matrix[0].size();
	vector<int> ans;

	if (m == 0)
		return ans;

	vector<vector<bool> > seen(m, vector<bool>(n, false));
	int dr[] = { 0, 1, 0, -1 };
	int dc[] = { 1, 0, -1, 0 };

	int x = 0, y = 0, di = 0;


	for (int i = 0; i < m * n; i++) {
		ans.push_back(matrix[x][y]);

		seen[x][y] = true;
		int newX = x + dr[di];
		int newY = y + dc[di];

		if (0 <= newX && newX < m && 0 <= newY && newY < n
			&& !seen[newX][newY]) {
			x = newX;
			y = newY;
		}
		else {
			di = (di + 1) % 4;
			x += dr[di];
			y += dc[di];
		}
	}
	return ans;
}


int main()
{
	vector<vector<int> > a{ { 1, 2, 3, 4 },
							{ 5, 6, 7, 8 },
							{ 9, 10, 11, 12 },
							{ 13, 14, 15, 16 } };


	for (int x : spiralOrder(a)) {
		cout << x << " ";
	}
	return 0;
}


