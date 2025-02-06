//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<vector<int>> adj(n);
	while (m--) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	using my_type = pair<vector<int>, int>;
	auto my_less{[](const my_type& a, const my_type& b) {
		if (a.fi.size() != b.fi.size()) return a.fi.size() < b.fi.size();
		else return a.fi < b.fi;
	}};

	vector<my_type> tmp(n);
	for (int v{0}; v < n; ++v) {
		adj[v].push_back(v);
		sort(adj[v].begin(), adj[v].end());
		tmp[v] = {adj[v], v};
	}
	sort(tmp.begin(), tmp.end(), my_less);

	vector<vector<int>> gp{};
	vector<int> id(n);
	for (int i{0}; i < n; ++i) {
		auto& [a, v]{tmp[i]};
		if (!i || a != tmp[i - 1].fi) gp.push_back({v});
		else gp.back().push_back(v);
		id[v] = gp.size() - 1;
	}
	if (gp.size() == 1) {
		cout << "YES\n";
		for (int v{0}; v < n; ++v) cout << 1 << " \n"[v == n - 1];
		return true;
	}

	vector<vector<int>> cadj{gp.size()};
	for (int u{0}; u < n; ++u)
		for (auto& v : adj[u]) {
			if (id[u] == id[v]) continue;
			cadj[id[u]].push_back(id[v]);
		}

	int s{-1};
	for (int v{0}; v < gp.size(); ++v) {
		sort(cadj[v].begin(), cadj[v].end());
		cadj[v].erase(unique(cadj[v].begin(), cadj[v].end()), cadj[v].end());
		if (cadj[v].size() > 2) return cout << "NO\n", true;
		else if (cadj[v].size() == 1) s = v;
	}
	if (s == -1) return cout << "NO\n", true;

	vector<int> ans(n);
	for (int i{0}, u{-1}, v{s}; i < gp.size(); ++i) {
		for (auto& ov : gp[v]) ans[ov] = i + 1;
		if (i + 1 < gp.size()) {
			if (cadj[v][0] == u) u = v, v = cadj[v][1];
			else u = v, v = cadj[v][0];
		}
	}

	cout << "YES\n";
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
