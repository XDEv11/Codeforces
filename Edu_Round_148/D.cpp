//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	ll n, q;
	cin >> n >> q;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	auto v2{v};
	for (int i{0}; i < n; ++i) v2[i] -= i;

	vector<ll> mn(n), df(n);
	for (int i{0}; i < n; ++i) {
		mn[i] = v2[i];
		if (i) {
			if (mn[i] > mn[i - 1]) {
				df[i] = df[i - 1] + mn[i] - mn[i - 1];
				mn[i] = mn[i - 1];
			} else df[i] = df[i - 1] + i * (mn[i - 1] - mn[i]);
		}
	}

	while (q--) {
		ll k;
		cin >> k;

		if (n == 1) {
			ll m{v[0] - k / 2 + (k & 1) * k};
			cout << m << ' ';
			continue;
		}

		if (k < n) {
			ll m1{mn[k - 1] + k}, m2{v[k]};
			cout << min(m1, m2) << ' ';
		} else if ((k - n) & 1) {
			ll m1{mn[n - 2] + k}, m2{v[n - 1]}, t{max(0ll, k - (n - 1) - 2 * df[n - 2]) / 2};
			if (m1 >= m2) t = max(0ll, t - (m1 - m2) * (n - 1)), m1 = m2;
			else t = max(0ll, t - (m2 - m1));
			m1 -= (t + n - 1) / n;
			cout << min(m1, m2) << ' ';
		} else {
			ll m{mn[n - 1] + k}, t{max(0ll, k - n - 2 * df[n - 1]) / 2};
			m -= (t + n - 1) / n;
			cout << m << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
