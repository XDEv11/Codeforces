//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		ll t;
		cin >> n >> t;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		sort(v.begin(), v.end());

		vector<ll> ps(n + 1);
		for (int i{0}; i < n; ++i) ps[i + 1] = ps[i] + v[i];

		ll ans{0};
		for (int i{0}; i < n; ++i) {
			int l{i}, r{n};
			while (r - l > 1) {
				int m{(l + r) / 2}, j{min(ll(i), t * (m - i - 1))}, k{min(ll(i), t * (m - i))};
				(v[m] - v[i] < v[i] * (k - j) - (ps[k] - ps[j]) ? l : r) = m;
			}

			int c{l - i}, d{min(ll(i), t * c)};
			ans = max(ans, ps[n] - ps[l + 1] + ps[i + 1] - ps[d] + v[i] * (c + d));
		}
		
		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
