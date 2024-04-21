#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t;
int a[9][9];

bool check(int xl, int yl, int xr, int yr) {
	vector<int> v;
	for (int i = xl; i < xr; i++)
		for (int j = yl; j < yr; j++)
			v.push_back(a[i][j]);
	sort(begin(v), end(v));
	for (int i = 0; i < 9; i++)
		if (v[i] != i + 1)
			return false;
	return true;
}

bool check() {
	for (int i = 0; i < 9; i++)
		if (!check(i, 0, i + 1, 9) || !check(0, i, 9, i + 1) || !check(i / 3 * 3, i % 3 * 3, (i / 3 + 1) * 3, (i % 3 + 1) * 3))
			return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (cin >> t; t--; ) {
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
				cin >> a[i][j];
		cout << check() << '\n';
	}
	return 0;
}

