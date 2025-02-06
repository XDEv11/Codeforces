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

	vector<int> r(n, 0);
	queue<int> qu{}, quf{};
	qu.push(0), r[0] = 1;
	for (auto& e : x) quf.push(e), r[e] = 2;

	while (!qu.empty()) {
		queue<int> nxt{};
		while (!quf.empty()) {
			auto u{quf.front()}; quf.pop();
			for (auto& v : adj[u])
				if (r[v] == 0 || r[v] == 1) r[v] = 2, nxt.push(v);
		}
		quf.swap(nxt);

		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto& v : adj[u]) {
				if (r[v] == 0) {
					if (adj[v].size() == 1) return cout << "YES\n"s, []{}();
					r[v] = 1, nxt.push(v); 
				}
			}
		}
		qu.swap(nxt);
	}

	cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
