//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> pa, sz;
public:
	explicit DSU(int n) : pa(n, -1), sz(n, 1) {}
	int find(int i) { // collapsing find
		return pa[i] == -1 ? i : pa[i] = find(pa[i]);
	}
	void unionn(int i, int j) { // weighted union
		auto ri{find(i)}, rj{find(j)};
		if (ri == rj) return ;
		if (sz[ri] < sz[rj]) swap(ri, rj);
		pa[rj] = ri, sz[ri] += sz[rj];
	}
};

namespace {
	using ll = long long;
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<tuple<int, int, ll>> e(m);
		vector<int> d(n);
		ll ans{};
		for (int i{m - 1}; i >= 0; --i) {
			auto& [u, v, w]{e[i]};
			cin >> u >> v >> w, ++d[--u], ++d[--v], ans += w;
		}

		vector<int> p(m + n);
		DSU dsu{n};
		vector<int> r(n);
		for (int v{0}; v < n; ++v) r[v] = m + v;
		for (int i{m - 1}; i >= 0; --i) {
			auto& [u, v, w]{e[i]};
			p[r[dsu.find(u)]] = p[r[dsu.find(v)]] = i;
			dsu.unionn(u, v), r[dsu.find(u)] = i;
		}

		vector<ll> mn(m);
		for (int i{0}; i < m; ++i) {
			auto& [u, v, w]{e[i]};
			mn[i] = (i ? min(w, mn[p[i]]) : w);
		}

		vector<int> c(m);
		for (int v{0}; v < n; ++v) {
			if (d[v] % 2) c[p[m + v]] += 1;
		}
		for (int i{m - 1}; i >= 0; --i) {
			if (c[i] == 2) ans += mn[i];
			else if (c[i] == 1) ++c[p[i]];
		}

		cout << ans << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
