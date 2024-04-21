#include <iostream>
#include <cstring>

using namespace std;

using P = pair<int, long long>;

int t;
int n, m, k;
char s[200005];
P fenwick[200005];

inline void build(int p) {
	if (s[p - 1] == '0')
		s[p - 1] = '2';
	for (int i = p; i <= n; i += i & -i)
		fenwick[i].first++, fenwick[i].second += p;
}

inline void erase(int p) {
	s[p - 1] = '0';
	for (int i = p; i <= n; i += i & -i)
		fenwick[i].first--, fenwick[i].second -= p;
}

inline P query(int l, int r) {
	P res;
	auto& [res1, res2] = res;
	for (int i = r; i != 0; i -= i & -i)
		res1 += fenwick[i].first, res2 += fenwick[i].second;
	for (int i = l - 1; i != 0; i -= i & -i)
		res1 -= fenwick[i].first, res2 -= fenwick[i].second;
	return res;
}

inline long long dis(int p) {
	int l = 0, r = max(p - 1, n - p), res;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (query(max(1, p - mid), min(n, p + mid)).first >= k)
			r = (res = mid) - 1;
		else
			l = mid + 1;
	}
	l = max(1, p - res);
	r = min(n, p + res);
	const auto [l1, l2] = query(l, p);
	const auto [r1, r2] = query(p + 1, r);
	return (1LL * l1 * p - l2) + (r2 - 1LL * r1 * p) - 1LL * (l1 + r1 - k) * res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (cin >> t; t--; ) {
		cin >> n >> m >> k;
		cin >> s;
		for (int i = 1; i <= n; i++)
			if (s[i - 1] == '1' || --m >= 0)
				build(i);
		for (int i = 1, l = 1, r = 1; i <= n; i++) {
			static auto justify = [&]() {
				while (l < i && s[l - 1] != '2')
					l++;
				while (r < i || (r <= n && s[r - 1] != '0'))
					r++;
			};
			long long res = dis(i);
			for (justify(); l < i && r <= n; justify()) {
				erase(l), build(r);
				if (long long nxt = dis(i); nxt < res)
					res = nxt;
				else {
					erase(r), build(l);
					break;
				}
			}
			cout << res << "\n "[i + 1 <= n];
		}
		memset(fenwick, 0, sizeof(pair<int, long long>) * (n + 1));
	}
	return 0;
}
