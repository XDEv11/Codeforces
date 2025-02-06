//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll l, r;
		cin >> n >> l >> r;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{};

		vector<ll> t{};
		for (auto& x : v) {
			if (x < l) ans += l - x;
			else if (r < x) ans += x - r;
			x = clamp(x, l, r);
		}

		sort(v.begin(), v.end());
		for (int i{0}; ; ++i) {
			int j{n - 1 - i};
			if (i >= j) break;
			ans += v[j] - v[i];
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
