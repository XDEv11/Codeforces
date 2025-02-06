//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

namespace {
	// fast disjoint set union
	class DSU {
		vector<int> pa, sz;
	public:
		explicit DSU(int n) : pa(n, -1), sz(n, 1) {}
		int find(int x) { // collapsing find
			return pa[x] == -1 ? x : pa[x] = find(pa[x]);
		}
		void unionn(int x, int y) { // weighted union
			auto rx{find(x)}, ry{find(y)};
			if (rx == ry) return ;
			if (sz[rx] < sz[ry]) swap(rx, ry);
			pa[ry] = rx, sz[rx] += sz[ry];
		}
	};
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto& x : a) cin >> x;

		vector<pair<int, int>> ans(n - 1);
		DSU dsu{n};
		for (int i{n - 1}; i >= 1; --i) {
			vector<bool> ck(n);
			ck[dsu.find(0)] = true;
			map<int, int> mp{};
			mp[0] = 0;
			for (int v{1}; v < n; ++v) {
				if (ck[dsu.find(v)]) continue;
				ck[dsu.find(v)] = true;

				int t{((a[v] - a[0]) % i + i) % i};
				if (mp.count(t)) {
					int u{mp[t]};
					ans[i - 1] = {u, v};
					dsu.unionn(u, v);
					break;
				} else mp[t] = v;
			}
		}

		cout << "YES\n";
		for (auto& [u, v] : ans) cout << (u + 1) << ' ' << (v + 1) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
