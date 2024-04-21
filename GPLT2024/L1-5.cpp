#include <iostream>
#include <vector>

using namespace std;

int n;
string s[105];
int k;
string t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	cin >> k;
	cin.get();
	getline(cin, t);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		vector<size_t> v;
		for (size_t p = t.find(s[i]); p != string::npos; p = t.find(s[i], p + s[i].length()))
			v.push_back(p), cnt++;
		string nxt;
		size_t p = 0;
		for (const auto& j : v) {
			nxt += t.substr(p, j - p);
			nxt += '\n';
			p = j + s[i].length();
		}
		nxt += t.substr(p);
		t = nxt;
	}
	if (cnt < k) {
		for (const auto& i : t) {
			if (i != '\n')
				cout << i;
			else
				cout << "<censored>";
		}
		cout << '\n';
	}
	else {
		cout << cnt << '\n';
		cout << "He Xie Ni Quan Jia!" << '\n';
	}
	return 0;
}

