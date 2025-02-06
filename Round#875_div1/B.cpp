//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	ll ans{0};
	for (ll m1{0}; m1 * m1 <= 2 * n; ++m1) {
		vector<ll> cnt(n + 1);
		for (int i{0}; i < n; ++i) {
			if (a[i] <= m1) continue;
			ll d{m1 * a[i] - b[i]};
			if (clamp(d, 1ll, n) == d) cnt[d] += 1;
		}
		for (int i{0}; i < n; ++i) {
			if (a[i] != m1) continue;
			ans += cnt[b[i]];
			ll d{m1 * a[i] - b[i]};
			if (clamp(d, 1ll, n) == d) cnt[d] += 1;
		}
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
