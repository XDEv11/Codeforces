//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll m, k;
	cin >> n >> m >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll ans{};
	ll q{k / m}, r{k % m};

	ans += k * (k - 1) / 2;
	for (int i{0}; i < q; ++i) ans -= m * (m - 1) / 2;
	if (r) ans -= r * (r - 1) / 2;

	sort(v.begin(), v.end());
	for (int i{0}; i < q; ++i) ans += m * v[i];
	if (r) ans += r * v[q];

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
