//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	ll max_pow2(ll x) {
		return x & -x;
	}
	void solve() {
		ll l, r;
		cin >> l >> r;
		if (l == r) return void(cout << "0\n");

		for (int i{62}; i >= 0 && (l >> i) == (r >> i); --i) {
			if (l >> i) l -= (1ll << i), r -= (1ll << i);
		}

		ll ans;
		if (l) {
			ans = min(max_pow2(l), max_pow2(r + 1));
			if (max_pow2(l + r + 1) == l + r + 1) ans *= 2;
		} else ans = max_pow2(r + 1);

		cout << ans - 1 << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
