//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

static void solve() {
	using ll = long long;
	ll x, y, k;
	cin >> x >> y >> k;

	while (k > 0 && x > 1) {
		ll t{min(k, y - (x % y))};
		x += t, k -= t;
		while (x % y == 0) x /= y;
	}
	x += k % (y - 1);

	cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
