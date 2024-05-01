#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int n, m;
int s[105][105];
int d[105][105];
queue<pair<int, int>> q;
int k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	int sx, sy;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> s[i][j];
			if (s[i][j] == 2)
				sx = i, sy = j;
			d[i][j] = -1;
		}
	}
	for (d[sx][sy] = 0, q.emplace(sx, sy); !q.empty(); ) {
		const auto& [x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
			if (const int X = x + dx[i], Y = y + dy[i]; s[X][Y] == 1 && d[X][Y] == -1)
				d[X][Y] = d[x][y] + 1, q.emplace(X, Y);
	}
	cin >> k;
	vector<pair<int, int>> v;
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> y >> x;
		if (d[x][y] != -1)
			v.emplace_back(d[x][y], i);
	}
	sort(begin(v), end(v));
	for (size_t l = 0, r = 0; l < v.size(); l = r) {
		while (r < v.size() && v[l].first == v[r].first)
			r++;
		if (l == r - 1) {
			cout << v[l].second << ' ' << v[l].first << '\n';
			return 0;
		}
	}
	cout << "No winner." << '\n';
	return 0;
}

