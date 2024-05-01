#include <iostream>

using namespace std;

int n, m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << max(0, sum - n * (m - 1)) << '\n';
	return 0;
}

