//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;

	int n;
	if (!(cin >> n)) return false;
	vector<vector<pair<ll, int>>> adj(n);
	int m{n * (n - 1) / 2};
	while (m--) {
		int u, v; ll w;
		cin >> u >> v >> w, --u, --v;
		adj[u].emplace_back(w, v);
		adj[v].emplace_back(w, u);
	}

	ll ans{};
	for (int v{0}; v < n; ++v) {
		sort(adj[v].rbegin(), adj[v].rend());
		for (int i{0}; i < n - 1; i += 2) ans += adj[v][i].fi;
	}

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
