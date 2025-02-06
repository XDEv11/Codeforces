//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll k;
	cin >> n >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	int c{};
	bool ls{}, gt{};
	for (auto& x : v) {
		if (x == k) ++c;
		else if (x < k) ls = true;
		else gt = true;
	}
	if (c) return cout << (c == n ? "0\n" : "-1\n"), []{}();
	else if (ls && gt) return cout << "-1\n", []{}();

	vector<ll> d(n);
	for (int i{0}; i < n; ++i) d[i] = abs(k - v[i]);

	ll ans{}, g{};
	for (auto& x : d) g = gcd(g, x);
	for (auto& x : d) ans += x / g - 1;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
