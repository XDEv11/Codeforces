//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n; ll t;
		cin >> n >> t;
		vector<array<ll, 3>> v(n);
		for (auto& [x, y, z] : v) cin >> x >> y >> z;

		for (auto& [x, y, z] : v) t -= x * (y - 1);
		if (t <= 0) return void(cout << "0\n");

		ll ans{t + 1};
		for (auto& [x, y, z] : v) {
			ll s{x * y - z};
			if (s <= 0) continue;
			ans = min(ans, (t + s - 1) / s);
		}
		if (ans == t + 1) return void(cout << "-1\n");

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
