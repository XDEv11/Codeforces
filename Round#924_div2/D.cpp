//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;
	int maxn{200000};

	int n; ll b, q;
	cin >> n >> b >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	auto calc{[](int x, int y) {
		if (x < y) return 0ll;
		int z{x / y}, r{x % y};
		ll a{r * (ll(z + 1) * z / 2) + (y - r) * (z * ll(z - 1) / 2)};
		return a;
	}};

	int l{0}, r{maxn};
	while (r - l > 1) {
		int m{(l + r) / 2};
		ll c{};
		for (auto& x : v) c += calc(x, m) - calc(x, m + 1);
		c *= b;
		if (c >= q) l = m;
		else r = m;
	}

	ll ans{};
	for (auto& x : v) ans += calc(x, 1) * b;
	for (auto& x : v) ans -= calc(x, r) * b;
	ans -= (r - 1) * q;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
