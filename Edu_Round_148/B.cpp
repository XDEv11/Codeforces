//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n, k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.rbegin(), v.rend());

	ll ans{0};
	for (int i{1}; i < n; ++i) v[i] += v[i - 1];
	for (int i{0}; i <= k; ++i) {
		ans = max(ans, v[n - 1 - 2 * (k - i)] - (i == 0 ? 0ll : v[i - 1]));
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
