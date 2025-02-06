//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n, k, d;
	if (!(cin >> n >> k >> d)) return false;
	vector<int> a(k);
	for (auto& w : a) cin >> w, --w;
	vector<vector<pair<int, int>>> adj(n);
	for (int j{0}; j < n - 1; ++j) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].emplace_back(v, j);
		adj[v].emplace_back(u, j);
	}

	vector<bool> ans(n - 1);
	queue<pair<int, int>> qu{};
	vector<bool> vis(n);
	for (auto& w : a) {
		if (vis[w]) continue;
		vis[w] = true, qu.emplace(w, -1);
	}
	for (int i{0}; i < d; ++i) {
		queue<pair<int, int>> nq{};
		while (!qu.empty()) {
			auto [u, w]{qu.front()}; qu.pop();
			for (auto& [v, j] : adj[u]) {
				if (vis[v]) continue;
				vis[v] = true, nq.emplace(v, u);
				ans[j] = true;
			}
		}
		qu = nq;
	}

	if (!count(vis.begin(), vis.end(), false)) {
		cout << count(ans.begin(), ans.end(), false) << '\n';
		for (int j{0}; j < n - 1; ++j) {
			if (ans[j]) continue;
			cout << j + 1 << ' ';
		}
		cout << '\n';
	} else cout << "-1\n";
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
