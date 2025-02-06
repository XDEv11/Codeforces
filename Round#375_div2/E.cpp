//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#define fi first
#define se second
#include <map>
#include <algorithm>

using namespace std;

vector<int> euler_cycle(vector<vector<pair<int, int>>>& adj, int w = 0) {
	int n{adj.size()}, m{};
	for (int v{0}; v < n; ++v) m += adj[v].size();
	m /= 2;

	stack<int> stk{};
	stk.push(w);
	vector<int> res{};
	vector<int> nxt(n);
	vector<bool> usd(m);
	while (!stk.empty()) {
		auto u{stk.top()};
		while (nxt[u] < adj[u].size() && usd[adj[u][nxt[u]].se]) ++nxt[u];
		if (nxt[u] < adj[u].size()) {
			auto [v, i]{adj[u][nxt[u]]};
			++nxt[u], usd[i] = true, stk.push(v);
		} else res.push_back(u), stk.pop();
	}
	return res;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n);
	for (int i{0}; i < m; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
	}

	int ans{n}, k{m};
	for (int v{0}, u{-1}; v < n; ++v) {
		if (adj[v].size() % 2 == 0) continue;
		if (u != -1) {
			ans -= 2;
			adj[u].emplace_back(v, k), adj[v].emplace_back(u, k++);
			u = -1;
		} else u = v;
	}

	map<pair<int, int>, int> mp{};
	for (int u{0}; u < n; ++u)
		for (auto& [v, i] : adj[u]) {
			if (i < m) mp[{u, v}] = i;
		}

	cout << ans << '\n';
	vector<bool> vis(n);
	for (int w{0}; w < n; ++w) {
		if (vis[w]) continue;
		auto ec{euler_cycle(adj, w)};
		for (int i{0}; i + 1 < ec.size(); ++i) {
			int u{ec[i]}, v{ec[i + 1]};
			vis[u] = true;
			if (mp.count({u, v})) cout << (u + 1) << ' ' << (v + 1) << '\n';
			mp.erase({u, v}), mp.erase({v, u});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
