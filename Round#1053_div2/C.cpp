//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(2 * n);
		for (auto& x : v) cin >> x;

		vector<ll> ps(2 * n);
		ps[0] = -v[0];
		for (int i{1}; i < 2 * n; ++i) ps[i] = ps[i - 1] + (i & 1 ? 1 : -1) * v[i];

		ll ans{ps[2 * n - 1]};
		for (int k{1}; k <= n; ++k) {
			cout << ans << ' ';
			if (k < n) ans += (k & 1 ? -1 : 1) * (ps[2 * n - 1 - k] - ps[k - 1]) * 2;
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
