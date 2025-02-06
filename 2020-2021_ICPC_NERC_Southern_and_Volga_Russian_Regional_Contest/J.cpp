//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

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
	using ll = long long;

	int n, m; ll k;
	cin >> n >> m >> k;
	vector<pair<ll, pair<int, int>>> a(m);
	for (auto& [w, e] : a) cin >> e.fi >> e.se >> w, --e.fi, --e.se;

	sort(a.begin(), a.end());

	DSU dsu{n};
	int c{n}, i;
	for (i = 0; i < m && a[i].fi <= k; ++i) {
		auto& [u, v]{a[i].se};
		if (dsu.find(u) == dsu.find(v)) continue;
		dsu.unionn(u, v), --c;
	}
	if (c == 1) {
		ll mx{-10000000000ll}, mn{10000000000ll};
		for (auto& [w, e] : a) {
			if (w <= k) mx = max(mx, w);
			else mn = min(mn, w);
		}
		cout << min(k - mx, mn - k) << '\n';
		return ;
	}

	ll ans{};
	for (; i < m; ++i) {
		auto& [w, e]{a[i]};
		auto& [u, v]{e};
		if (dsu.find(u) == dsu.find(v)) continue;
		dsu.unionn(u, v), ans += w - k;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
