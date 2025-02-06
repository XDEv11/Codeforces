//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll k;
	cin >> n >> k;
	vector<pair<pair<int, int>, ll>> v(n);
	for (auto& [t, x] : v) cin >> t.fi >> t.se >> x;

	const ll inf{n * k};

	vector<vector<ll>> rem0(n, vector<ll>(n, inf)), rem1{rem0};
	for (int i{0}; i < n; ++i) {
		ll c{k};
		for (int j{i}; j < n; ++j) {
			if (!c && v[j - 1].fi.se < v[j].fi.fi) c = k;
			const auto& [t, x]{v[j]};
			if (c >= x) {
				c -= x;
				if (t.fi < t.se) {
					rem0[i][j] = (j == n - 1 ? 0 : c);
					if (!c) c = k;
				} else rem1[i][j] = (j == n - 1 ? 0 : c);
			} else {
				ll d{(x - c + k - 1) / k};
				if (t.fi + d > t.se) break;
				c = (k - (x - c - d * k)) % k;
				if (t.fi + d < t.se) {
					rem0[i][j] = (j == n - 1 ? 0 : c);
					if (!c) c = k;
				} else rem1[i][j] = (j == n - 1 ? 0 : c);
			}
		}
	}

	vector<ll> dp0(n, inf), dp1(n, inf);
	for (int j{0}; j < n; ++j)
		for (int i{0}; i <= j; ++i) {
			dp0[j] = min(dp0[j], (i ? dp0[i - 1] : 0) + rem0[i][j]);
			dp1[j] = min(dp1[j], (i ? dp0[i - 1] : 0) + rem1[i][j]);
			if (i && v[i - 1].fi.se < v[i].fi.fi) {
				dp0[j] = min(dp0[j], dp1[i - 1] + rem0[i][j]);
				dp1[j] = min(dp1[j], dp1[i - 1] + rem1[i][j]);
			}
		}

	ll ans{min(dp0[n - 1], dp1[n - 1])};
	if (ans == inf) return cout << "-1\n", []{}();
	for (int i{0}; i < n; ++i) ans += v[i].se;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
