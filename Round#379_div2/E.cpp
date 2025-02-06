//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
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

// tree diameter
int dfs(const vector<vector<int>>& adj, int& diam, int u, int w = -1) {
    int mx{0};
    for (auto& v : adj[u]) {
        if (v != w) {
            auto len{1 + dfs(adj, diam, v, u)};
            diam = max(diam, mx + len);
            mx = max(mx, len);
        }
	}
    return mx;
}

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> c(n);
	for (auto& x : c) cin >> x;
	vector<vector<int>> adj(n);
	for (int _{0}; _ < n - 1; ++_) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	DSU dsu{n};
	for (int u{0}; u < n; ++u)
		for (auto& v : adj[u]) {
			if (c[u] != c[v]) continue;
			dsu.unionn(u, v);
		}

	vector<vector<int>> cadj(n);
	for (int u{0}; u < n; ++u)
		for (auto& v : adj[u]) {
			if (c[u] == c[v]) continue;
			cadj[dsu.find(u)].push_back(dsu.find(v));
		}
	int d{0};
	dfs(cadj, d, dsu.find(0));

	return cout << (d + 1) / 2 << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
