#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// topological sort 1
optional<vector<int>> top_sort(vector<vector<int>>& adj) {
	vector<int> res{};
	int n{static_cast<int>(adj.size())}; vector<int> cnt(n, 0); // predecessor count
	for (int u{0}; u < n; ++u)
		for (auto& v : adj[u]) ++cnt[v];
	
	queue<int> qu{};
	for (int u{0}; u < n; ++u) if (!cnt[u]) qu.push(u);
	while (!qu.empty()) {
		auto u{qu.front()}; qu.pop();
		res.push_back(u);
		
		for (auto& v : adj[u]) {
			--cnt[v];
			if (!cnt[v]) qu.push(v);
		}
	}
	
	for (int u{0}; u < n; ++u) if (cnt[u]) return nullopt;
	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);

	for (int u{0}; u < n; ++u) {
		int k;
		cin >> k;
		while (k--) {
			int v;
			cin >> v;
			adj[u].push_back(v);
		}
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
