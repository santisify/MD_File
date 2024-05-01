#include <iostream>

using namespace std;

int n;
int p[105];
int cnt[105];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		p[i] = stoi(s.substr(0, s.length() - 3)) * 100 + stoi(s.substr(s.length() - 2));
	}
	int res = 0;
	for (int x, y; cin >> x >> y; )
		cnt[x] += y, res += p[x] * y;
	for (int i = 1; i <= n; i++)
		cout << cnt[i] << '\n';
	cout << res / 100 << '.' << res / 10 % 10 << res % 10 << '\n';
	return 0;
}

