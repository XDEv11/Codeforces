//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

static void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());
	const auto& mx{v.back()};

	{ll y{1};
	for (auto& x : v) {
		if ((y = lcm(y, x)) > mx) return cout << n << '\n', []{}();
	}}

	vector<ll> d{};
	for (ll z{1}; z * z <= mx; ++z) {
		if (mx % z) continue;
		d.push_back(z);
		if (z < mx / z) d.push_back(mx / z);
	}

	int ans{};
	for (auto& z : d) {
		ll y{1}; int c{};
		for (auto& x : v) {
			if (x >= z) {
				if (x == z) y = 0;
				break;
			}
			if (z % x) continue;
			y = lcm(y, x), ++c;
		}
		if (y == z) ans = max(ans, c);
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
