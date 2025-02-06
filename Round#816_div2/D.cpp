//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<vector<pair<int, unsigned>>> v(n);
	while (q--) {
		int i, j; unsigned x;
		cin >> i >> j >> x, --i, --j;
		if (i > j) swap(i, j);
		v[i].emplace_back(j, x);
	}

	vector<unsigned> ans(n, 0);
	for (int b{0}; b < 30; ++b) {
		vector<bool> fix(n);
		for (int i{0}; i < n; ++i) {
			for (auto& [j, x] : v[i]) {
				if ((x >> b) & 1) continue;
				fix[i] = fix[j] = true;
			}
		}
		for (int i{0}; i < n; ++i) {
			if ((ans[i] >> b) & 1) continue;
			bool f{false};
			for (auto& [j, x] : v[i]) {
				if (!((x >> b) & 1)) continue;
				f = (f || fix[j] || i == j);
			}
			if (!f) {
				for (auto& [j, x] : v[i]) {
					if (!((x >> b) & 1)) continue;
					ans[j] |= (1u << b);
				}
			} else ans[i] |= (1u << b);
		}
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
