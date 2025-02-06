//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		if (n & 1) {
			ll ans{numeric_limits<ll>::max()};
			for (int k{0}; k < n; ++k) {
				ll a{1};
				for (int i{0}; ; ) {
					int x{i == k ? i + 1 : i}, y{x + 1 == k ? x + 2 : (x + 1)};
					if (!(y < n)) break;
					a = max(a, v[y] - v[x]);
					i = y + 1;
				}
				ans = min(ans, a);
			}
			cout << ans << '\n';
		} else {
			ll ans{1};
			for (int i{0}; i < n; i += 2) ans = max(ans, v[i + 1] - v[i]);
			cout << ans << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
