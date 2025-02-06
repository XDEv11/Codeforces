//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		ll n;
		cin >> n;
		vector<bool> v(n);
		for (int i{0}; i < n; ++i) {
			char c{};
			cin >> c, v[i] = (c == '1');
		}

		int d{};
		for (int i{0}, c{}; i < n; ++i) {
			c += v[i];
			d = max(d, c - (i + 1) / 2);
		}
		for (int i{0}; i < n && d > 0; ++i) d -= v[i], v[i] = false;

		ll ans{};
		for (int i{0}; i < n; ++i) {
			if (v[i]) continue;
			ans += (i + 1);
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
