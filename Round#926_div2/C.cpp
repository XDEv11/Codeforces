//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll k, x, a;
	cin >> k >> x >> a;

	ll b{a - 1}, c{1};
	for (int i{2}; i <= x; ++i) {
		ll d{(c + 1 + k - 2) / (k - 1)};
		if (b < d) return cout << "NO\n", []{}();
		c += d, b -= d;
	}
	cout << (b * k > a ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
