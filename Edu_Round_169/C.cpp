//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;
		int n; ll k;
		cin >> n >> k;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		sort(v.rbegin(), v.rend());

		ll ans{};
		for (int i{0}; i < n; ++i) ans += v[i] * (i & 1 ? -1 : 1);
		for (int i{1}; i < n; i += 2) {
			ll t{min(k, v[i - 1] - v[i])};
			k -= t, ans -= t;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
