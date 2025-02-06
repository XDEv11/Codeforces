//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void solve() {
	using ll = long long;
	int n; ll k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	int i{0};
	while (i + 1 < n) {
		ll t{k / (i + 1)};
		if (v[i + 1] - v[i] <= t) {
			k -= (v[i + 1] - v[i]) * (i + 1);
			++i;
		} else {
			v[i] += t, k -= t * (i + 1);
			break;
		}
	}

	ll ans{1 + (v[i] - 1) * n + k};
	for (int j{i + 1}; j < n; ++j) ans += (v[j] > v[i]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
