//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		ll ans{};
		for (auto& x : v) ans += x;

		for (int k{0}; k < 2; ++k) {
			int mx{0};
			vector<int> cnt(n + 1);
			for (int i{0}; i < n; ++i) {
				if (++cnt[v[i]] >= 2) {
					if (v[i] > mx) mx = v[i];
				}
				v[i] = mx;
			}
			for (auto& x : v) ans += x;
		}

		for (int i{n - 2}; i >= 0; --i) ans += ll(v[i]) * (n - 1 - i);

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
