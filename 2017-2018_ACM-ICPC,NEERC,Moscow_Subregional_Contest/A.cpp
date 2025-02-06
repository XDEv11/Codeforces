//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

using ll = long long;

ll ceil_log2(ll n) {
	ll l{-1}, r{63};
	while (r - l > 1) {
		int m{(l + r) / 2};
		((1ll << m) < n ? l : r) = m;
	}
	return r;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	if (k >= n) return cout << "1\n", []{}();

	ll ans{numeric_limits<ll>::max()};
	for (ll i{1}; i < k; ++i) {
		ll t{ceil_log2((n / 3 + 1 + i - 1) / i)};
		ll r{n - i * (1ll << t)};
		//
		if (!t) t = 1, r = (r + 1) / 2;
		t += ceil_log2((r + k - i - 1) / (k - i)) + 1;
		ans = min(ans, t);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
