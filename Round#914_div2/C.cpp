//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	if (k <= 2) {
		ll ans{numeric_limits<ll>::max()};
		sort(v.begin(), v.end());
		for (int i{0}; i + 1 < n; ++i) ans = min(ans, v[i]);
		for (int i{0}; i + 1 < n; ++i) ans = min(ans, v[i + 1] - v[i]);
		if (k == 2) {
			for (int i{0}; i < n; ++i)
				for (int j{i + 1}; j < n; ++j) {
					ll x{v[j] - v[i]};
					auto it{lower_bound(v.begin(), v.end(), x)};
					if (it != v.end()) ans = min(ans, *it - x);
					if (it != v.begin()) ans = min(ans, x - *prev(it));
				}
		}
		cout << ans << '\n';
	} else cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
