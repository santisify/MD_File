#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
unordered_set<int> s[100005];
int q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		for (cin >> k; k--; ) {
			int x;
			cin >> x;
			s[i].insert(x);
		}
	}
	for (cin >> q; q--; ) {
		int x, y;
		cin >> x >> y;
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (s[i].find(x) != s[i].end() && s[i].find(y) != s[i].end())
				res++;
		cout << res << '\n';
	}
	return 0;
}

