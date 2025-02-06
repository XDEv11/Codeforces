//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll L{ll(1e18 + 0.5)};
	void solve() {
		ll s, t;
		cin >> s >> t;

		ll l{0}, r{L + 1};
		while (r - l > 1) {
			ll m{(l + r) / 2}, c{};
			for (int k{59}; k >= 0; --k) {
				c <<= 1;
				if (s & (1ll << k)) ++c;
				if (t & (1ll << k)) c = max(0ll, c - m);
			}
			(c ? l : r) = m;
		}

		if (r == L + 1) cout << "-1\n";
		else cout << r << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
