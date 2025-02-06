//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// fast disjoint set union
class DSU {
public:
    vector<int> pa, sz;
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
	int n, l, r;
	cin >> n >> l >> r;
	vector<vector<int>> adj(n);
	for (int i{0}; i < n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DSU dsu{n};
	for (int u{0}; u < n; ++u)
		for (auto& v : adj[u]) dsu.unionn(u, v);

	int nim{0};
	for (int u{0}; u < n; ++u) {
		if (dsu.pa[u] != -1) continue;
		if (dsu.sz[u] < l + r) nim ^= dsu.sz[u] / l;
	}
	
	cout << (nim ? "Alice\n" : "Bob\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
