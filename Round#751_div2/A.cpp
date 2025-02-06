#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	char c{'z'};
	for (auto& x : s) {
		if (x < c) c = x;
	}
	cout << c << ' ';

	bool f{true};
	for (auto& x : s) {
		if (f && x == c) f = false;
		else cout << x;
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
