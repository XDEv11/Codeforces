//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#define fi first
#define se second
#include <array>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m, q;
		cin >> n >> m >> q;
		array<vector<pair<int, int>>, 2> v{};
		while (q--) {
			int c, l, r;
			cin >> c >> l >> r, --l;
			v[c - 1].emplace_back(l, r);
		}

		vector<int> ans(n);

		sort(v[0].begin(), v[0].end());
		int z{0};
		for (auto& [x, y] : v[0]) {
			x = max(x, z);
			for (int i{x}; i < y; ++i) ans[i] = m;
			z = max(z, y);
		}

		sort(v[1].begin(), v[1].end());
		z = 0;
		for (auto& [x, y] : v[1]) {
			x = max(x, z);
			for (int i{x}; i < y; ++i) {
				if (ans[i]) ans[i] = m + 1;
			}
			z = max(z, y);
		}

		for (int i{0}, k{0}; i < n; ++i) {
			if (ans[i]) continue;
			ans[i] = k;
			k = (k + 1) % m;
		}

		for (auto& x : ans) cout << x << ' ';
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
