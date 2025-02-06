//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	int l, r, k;
	cin >> l >> r >> k;

	if (l == r) return cout << (l == 1 ? "NO\n"s : "YES\n"s), []{}();

	int cnt{(r - l + 1) / 2 + (r & l & 1)};
	cout << (cnt <= k ? "YES\n"s : "NO\n"s);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
