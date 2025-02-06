//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll x, m;
		cin >> x >> m;

		// (x^y) % lcm(x, y) == 0
		ll ans{x <= m};

		// (x^y) % x == 0
		{
			ll t{(m - x) / x};
			if (t) {
				ans += t - 1;
				ans += (((x * (t + 1)) ^ x) <= m);
			}
			ans += (((x * (t + 2)) ^ x) <= m);
		}

		// (x^y) % y == 0
		for (ll y{1}; y <= min(x - 1, m); ++y) {
			ll t{x ^ y};
			ans += (t % y == 0);
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
