//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	int j; ll y{numeric_limits<ll>::min()};
	for (int i{0}; i < n; ++i) {
		ll x{min(a[i], b[i])};
		if (x > y) y = x, j = i;
	}
	int k; ll z{numeric_limits<ll>::max()};
	for (int i{0}; i < n; ++i) {
		ll x{max(a[i], b[i])};
		if (x < z) z = x, k = i;
	}
	if (y > z) swap(b[j], b[k]);

	ll ans{};
	for (int i{0}; i < n; ++i) ans += abs(a[i] - b[i]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
