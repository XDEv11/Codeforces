//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	while (m--) {
		int a, b;
		cin >> a >> b, --a, --b;
		adj[b].push_back(a);
	}

	vector<int> d(n);
	queue<int> qu{};
	qu.push(0), d[0] = 1;
	while (!qu.empty()) {
		auto u{qu.front()}; qu.pop();
		for (auto& v : adj[u]) {
			if (d[v]) continue;
			qu.push(v), d[v] = d[u] + 1;
		}
	}

	vector<vector<int>> cnt(n + 1);
	for (int i{0}; i < n; ++i) cnt[d[i]].push_back(i);
	if (!cnt[0].empty()) return cout << "INFINITE\n", []{}();

	vector<int> ans{};
	for (int i{n}; i >= 1; --i)
		for (int j{i}; j <= n; ++j)
			for (auto& x : cnt[j]) ans.push_back(x);

	cout << "FINITE\n";
	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
