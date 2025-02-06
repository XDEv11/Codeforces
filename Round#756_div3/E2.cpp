#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> x(k);
	for (auto& e : x) cin >> e, --e;
	vector<vector<int>> adj(n);
	for (int i{0}; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
