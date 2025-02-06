//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll h, r;
		cin >> n >> h >> r;
		vector<ll> v(n);
		ll s{};
		for (auto& x : v) cin >> x, s += x;

		ll ans{(n + r) * ((h - 1) / s)};
		h = (h - 1) % s + 1;

		ll mn{numeric_limits<ll>::max()};
		vector<ll> smx{v};
		for (int i{n - 2}; i >= 0; --i) smx[i] = max(smx[i], smx[i + 1]);
		for (int i{0}; i < n; ++i) {
			h -= v[i], mn = min(mn, v[i]);

			if (h <= 0 || h - (smx[i + 1] - mn) <= 0) return void(cout << (ans + i + 1) << '\n');
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
