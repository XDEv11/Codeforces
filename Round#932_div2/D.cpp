//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll ans{(k + 1) * k / 2 + (k + 1)};
	for (int i{0}; i < n; ++i) ans -= v[i] / 2 + 1;
	for (int i{n - 1}, c0{}, c1{}; i >= 0; --i) {
		ans -= (k + 1) - v[i];
		if (v[i] & 1) ans += ++c1;
		else ans += ++c0;
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
