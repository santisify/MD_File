#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, vector<string>> m;
int q;

string capital(const string& s) {
	string res;
	char prv = ' ';
	for (const auto& i : s) {
		if (prv == ' ' && islower(i))
			res += i;
		prv = i;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	cin.get();
	for (int i = 1; i <= n; i++) {
		string s;
		getline(cin, s);
		m[capital(s)].push_back(s);
	}
	for (auto& [k, v] : m)
		sort(begin(v), end(v));
	for (cin >> q, cin.get(); q--; ) {
		string s;
		getline(cin, s);
		auto& res = m[capital(s)];
		if (res.empty())
			cout << s << '\n';
		else {
			for (size_t i = 0; i < res.size(); i++)
				cout << res[i] << "\n|"[i + 1 < res.size()];
		}
	}
	return 0;
}
