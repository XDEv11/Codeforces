//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>

using namespace std;

void solve() {
	using ll = long long;

	ll n, x, y;
	cin >> n >> x >> y;
	if (x < y) swap(x, y);

	ll l{0}, r{n + 1};
	while (r - l > 1) {
		ll m{(l + r) / 2};
		if (m * x + (n - m) * y <= n - 1) l = m;
		else r = m;
	}
	if (l * x + (n - l) * y != n - 1) return cout << "-1\n", []{}();

	for (int i{0}; i < l; ++i)
		for (int j{0}; j < x; ++j) cout << i * x + 1 + 1 << ' ';
	for (int i{0}; i < n - l; ++i)
		for (int j{0}; j < y; ++j) cout << l * x + i * y + 1 + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
