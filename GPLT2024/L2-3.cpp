#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int p[100005];
vector<int> g[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		sort(begin(g[i]), end(g[i]));
	vector<int> res;
	int mx = 0, mn = n - 1;
	auto dfs = [&](int cur, auto&& self) -> void {
		res.push_back(cur);
		if (!g[cur].empty()) {
			mx = max<int>(mx, g[cur].size());
			mn = min<int>(mn, g[cur].size());
		}
		for (const auto& i : g[cur])
			self(i, self);
	};
	dfs(g[0].back(), dfs);
	cout << mx << ' ' << (mx == mn ? "yes" : "no") << '\n';
	for (int i = 0; i < n; i++)
		cout << res[i] << "\n "[i + 1 < n];
	return 0;
}

