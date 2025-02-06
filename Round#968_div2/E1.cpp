//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(m);
		for (auto& [l, r] : v) cin >> l >> r, --l, --r;

		ll c1{}, c2{};
		for (auto& [l, r] : v) c1 += r - l, c2 += 1;

		ll ans{};
		{
			ll c0{n - (c1 + c2)};
			ans += c0 * (c0 - 1) / 2 + c0 * (c1 + c2);
		}
		cerr << "ans=" << ans << '\n';
		for (auto& [l, r] : v) {
			ll t{r - l};
			c1 -= t, c2 -= 1;

			ans += c2;
			ans += t * (t - 1) / 2 + t * c1;
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
