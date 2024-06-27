#include <iostream>

#include <vector>

using namespace std;

int l, n;
int a[4];
int v[300][4];
bool vis[10000];
int cnt;
int sum[4];
int res;

void dfs1(int p, int s) {
	if (p == n) {
		int h = 0;
		for (int i = 0; i < n; i++)
			v[cnt][i] = a[i], h = h * (l + 1) + a[i];
		vis[h] = true;
		cnt++;
		return;
	}
	for (int i = p + 1 != n ? 0 : l - s; i <= min(l, l - s); i++) {
		a[p] = i;
		dfs1(p + 1, s + i);
	}
}

void dfs2(int p) {
	for (int i = 0; i < n; i++)
		if (sum[i] > l)
			return;
	if (p + 1 == n) {
		int h = 0;
		for (int i = 0; i < n; i++)
			h = h * (l + 1) + (l - sum[i]);
		if (vis[h])
			res++;
		return;
	}
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < n; j++)
			sum[j] += v[i][j];
		dfs2(p + 1);
		for (int j = 0; j < n; j++)
			sum[j] -= v[i][j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> l >> n;
	dfs1(0, 0);
	dfs2(0);
	cout << res << '\n';
	return 0;
}

