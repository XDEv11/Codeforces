#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<array<char, 2>> v(n);
	for (auto& [x, y] : v) cin >> x;
	for (auto& [x, y] : v) cin >> y;

	bool flag{true};
	for (auto& [x, y] : v)
		if (x == '1' && y == '1') flag = false;

	cout << (flag ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
