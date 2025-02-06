//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll t, n, m;
	cin >> t >> n >> m;
	vector<ll> a(m), b(m);
	for (int i{0}; i < m; ++i) cin >> a[i] >> b[i], --a[i];

	auto sum{[](ll x, ll y) {
		return (abs(y - x) + 1) * (x + y) / 2;
	}};

	ll mn{}, mx{};
	for (int i{0}; i < m; ++i) mn -= b[i], mx -= b[i];
	mn += sum(max(0ll, b[0] - a[0]), b[0]);
	mn += sum(b[m - 1], max(b[m - 1] - (n - 1 - a[m - 1]), 0ll));
	mx += sum(b[0] + a[0], b[0]);
	mx += sum(b[m - 1], b[m - 1] + (n - 1 - a[m - 1]));
	for (int i{0}; i + 1 < m; ++i) {
		ll hi{max(b[i], b[i + 1])}, lo{min(b[i], b[i + 1])};
		if (hi - lo + 1 > a[i + 1] - a[i] + 1) return cout << "No\n", []{}();
		ll len{(a[i + 1] - a[i] + 1) - (hi - lo + 1)};
		{
			ll tmp{sum(b[i], b[i + 1])};
			mn += tmp, mx += tmp;
		}
		if (len < 2 * (lo + 1) - 1) {
			ll tmp{lo - len / 2};
			mn += 2 * sum(lo, tmp) - !(len & 1) * tmp - lo;
		} else mn += 2 * sum(lo, 0) - lo;
		{
			ll tmp{hi + len / 2};
			mx += 2 * sum(hi, tmp) - !(len & 1) * tmp - hi;
		}
	}

	cout << (clamp(t, mn, mx) == t ? "Yes\n" : "No\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
