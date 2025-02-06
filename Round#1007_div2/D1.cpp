//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll l, r;
		cin >> n >> l >> r;
		vector<int> v(n);
		for (auto& e : v) cin >> e;

		if (n % 2 == 0) {
			int x{};
			for (int i{0}; i < n / 2; ++i) x ^= v[i];
			v.push_back(x), ++n;
		}
		if (l <= n) return cout << v[l - 1] << '\n', []{}();

		int x{};
		for (auto& e : v) x ^= e;

		int ans{};
		while (l / 2 > n) {
			ans ^= x;
			if ((l /= 2) % 2 == 1) return cout << ans << '\n', []{}();
		}
		for (int i{0}; i < l / 2; ++i) ans ^= v[i];

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
