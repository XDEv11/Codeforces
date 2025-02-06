//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define fi first
#define se second
#include <algorithm>
#include <iomanip>

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

	vector<double> ans(n);
	priority_queue<pair<double, int>> pq{};
	vector<bool> vis(n);
	vector<double> aux1(n);
	vector<int> aux2(n);
	ans[n - 1] = 0;
	pq.emplace(0, n - 1);
	while (!pq.empty()) {
		auto [e, u]{pq.top()}; pq.pop();
		if (vis[u]) continue;
		ans[u] = -e, vis[u] = true;
		for (auto& v : adj[u]) {
			if (vis[v]) continue;
			aux1[v] += ans[u], aux2[v] += 1;
			pq.emplace(-((adj[v].size() + aux1[v]) / (aux2[v])), v);
		}
	}

	cout << ans[0] << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(6);
	
	while (solve()) ;
}
