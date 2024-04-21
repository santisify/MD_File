#include <iostream>
#include <vector>

using namespace std;

int l, r;
int mx = -1;
vector<int> res;

int solve(int x) {
	if (x < 10)
		return 0;
	int m = 1;
	for (; x != 0; x /= 10)
		m *= x % 10;
	return m < 10 ? 1 : solve(m) + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> l >> r;
	for (int i = l; i <= r; i++) {
		if (const int k = solve(i); k == mx)
			res.push_back(i);
		else if (k > mx)
			mx = k, res.clear(), res.push_back(i);
	}
	cout << mx << '\n';
	for (size_t i = 0; i < res.size(); i++)
		cout << res[i] << "\n "[i + 1 < res.size()];
	return 0;
}

