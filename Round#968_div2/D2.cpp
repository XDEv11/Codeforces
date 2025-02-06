//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>
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

		vector<pair<int, int>> t{};
		for (auto& v : a) {
			auto n{v.size()};

			int j{0};
			while (j < n && v[j] == j) ++j;
			t.emplace_back(j, 0);
			while (j < n && v[j] == j + 1) ++j;
			t.back().se = j + 1;
		}
		sort(t.rbegin(), t.rend());

		int mx{};
		map<int, int> mp{};
		for (auto& [x, y] : t) {
			bool f{mp.count(x)};

			auto it{mp.find(y)};
			mp[x] = max(mp[x], it != mp.end() ? it->se : y);
			mx = max(mx, x);

			if (f) mx = max(mx, mp[x]);
		}

		ll ans{};
		int c{};
		for (auto& [x, y] : mp) {
			if (x > k) continue;
			ans += max(mx, y), ++c;
		}
		if (k < mx) ans += (k + 1 - c) * mx;
		else {
			ans += ll(mx + 1 - c) * mx;
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
