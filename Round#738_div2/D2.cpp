#include <iostream>
#include <vector>

using namespace std;

// fast disjoint set union
class DSU {
	vector<int> p, sz;
public:
	explicit DSU(int n) : p(n, -1), sz(n, 1) {}
	int find(int x) { // collapsing find
		return p[x] == -1 ? x : p[x] = find(p[x]);
	}
	void unionn(int x, int y) { // weighted union
		auto rx{find(x)}, ry{find(y)};
		if (rx == ry) return ;
		if (sz[rx] < sz[ry]) swap(rx, ry);
		p[ry] = rx, sz[rx] += sz[ry];
	}
};

void solve() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;

	DSU M{n}, D{n};
	while (m1--) {
		int u, v;
		cin >> u >> v, --u, --v;
		M.unionn(u, v);
	}
	while (m2--) {
		int u, v;
		cin >> u >> v, --u, --v;
		D.unionn(u, v);
	}

	vector<pair<int, int>> ans{};
	for (int u{0}; u < n; ++u)
		for (int v{u + 1}; v < n; ++v)
			if (M.find(u) != M.find(v) && D.find(u) != D.find(v)) {
				ans.emplace_back(u, v);
				M.unionn(u, v), D.unionn(u, v);
			}

	cout << ans.size() << '\n';
	for (auto& [u, v] : ans) cout << u + 1 << ' ' << v + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
