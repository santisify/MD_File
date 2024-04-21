#include <iostream>

using namespace std;

int a, b;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> a >> b;
	if (a == 2 || b == 1)
		cout << '-' << '\n';
	else if (a == 0)
		cout << "biii" << '\n';
	else
		cout << "dudu" << '\n';
	if (a == 1)
		cout << "move" << '\n';
	else
		cout << "stop" << '\n';
	return 0;
}

