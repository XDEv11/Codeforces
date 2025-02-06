//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll ans{};
		for (int i{0}; i + 1 < n; i += 2) {
			if (v[i] > v[i + 1]) ans += v[i] - v[i + 1], v[i] = v[i + 1];
			if (i + 2 < n) {
				ll t{v[i] + v[i + 2] - v[i + 1]};
				if (t > 0) ans += t, v[i + 2] -= t;
			}
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
