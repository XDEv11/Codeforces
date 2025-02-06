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

		vector<ll> d(n);
		for (int i{1}; i < n; ++i) {
			if (v[i] < v[i - 1]) d[i] = v[i - 1] - v[i], v[i] = v[i - 1];
		}

		ll ans{};
		for (auto& x : d) ans = max(ans, x);
		for (auto& x : d) ans += x;

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
