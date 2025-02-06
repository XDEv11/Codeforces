//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		int m; ll k;
		cin >> m >> k;
		vector<vector<int>> a(m);
		for (auto& v : a) {
			int n; cin >> n;
			v.resize(n);
			for (auto& x : v) cin >> x;

			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
		}

		int mx{};
		for (auto& v : a) {
			auto n{v.size()};

			int j{0};
			while (j < n && v[j] == j) ++j;
			while (j < n && v[j] == j + 1) ++j;
			mx = max(mx, j + 1);
		}

		ll ans{};
		if (k < mx) ans = (k + 1) * mx;
		else {
			ans = ll(mx + 1) * mx;
			ans += (mx + 1 + k) * (k - mx) / 2;
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
