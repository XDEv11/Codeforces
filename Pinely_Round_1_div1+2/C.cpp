//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>
#include <optional>
#include <queue>
#include <algorithm>

using namespace std;

// topological sort 1
optional<vector<int>> top_sort(vector<vector<int>>& adj) {
    vector<int> res{};
    int n{static_cast<int>(adj.size())};
    vector<int> cnt(n, 0); // predecessor count
    for (int u{0}; u < n; ++u)
        for (auto& v : adj[u]) ++cnt[v];
    
    queue<int> qu{};
    for (int u{0}; u < n; ++u) if (!cnt[u]) qu.push(u);
    while (!qu.empty()) {
        auto u{qu.front()}; qu.pop();
        res.push_back(u);
        
        for (auto& v : adj[u])
            if (!--cnt[v]) qu.push(v);
    }
    
    if (res.size() != adj.size()) return nullopt;
    return res;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<set<int>> ans(n);
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < n; ++j) {
			char c; cin >> c;
			if (c == '1') adj[i].push_back(j);
		}

	for (int i{0}; i < n; ++i) ans[i] = {i + 1};
	auto order{top_sort(adj).value()};
	for (auto& u : order)
		for (auto& v : adj[u]) {
			for (auto& x : ans[u]) ans[v].insert(x);
		}

	for (int i{0}; i < n; ++i) {
		cout << ans[i].size() << ' ';
		for (auto& x : ans[i]) cout << x << ' ';
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
