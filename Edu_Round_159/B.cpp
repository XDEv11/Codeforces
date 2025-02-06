//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll n, p, x, y;
	cin >> n >> p >> x >> y;

	ll l{-1}, r{n};
	while (r - l > 1) {
		ll m{(l + r) / 2};
		if (m * x + min((n + 6) / 7, 2 * m) * y < p) l = m;
		else r = m;
	}

	cout << (n - r) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
