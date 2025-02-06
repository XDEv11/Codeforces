#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <algorithm>

using namespace std;

bool solve() {
	int n, m, k, s, t;
	if (!(cin >> n >> m >> k >> s >> t)) return false;
	if (--s == --t) return cout << k << '\n', true;

	vector<vector<array<int, 3>>> adj(n);
	vector<int> a{};
	for (int i{0}; i < m; ++i) {
		int u, v, mn, mx;
		cin >> u >> v >> mn >> mx, --u, --v;
		adj[u].push_back({v, mn, mx});
		a.push_back(mn), a.push_back(mx);
	}

	auto test{[&](int x) {
		queue<int> qu{};
		vector<bool> vis(n);
		qu.push(s), vis[s] = true;
		while (!qu.empty()) {
			auto u{qu.front()}; qu.pop();
			for (auto& [v, mn, mx] : adj[u]) {
				if (vis[v] || clamp(x, mn, mx) != x) continue;
				if (v == t) return true;
				qu.push(v), vis[v] = true;
			}
		}
		return false;
	}};

	int ans{};
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	for (int i{0}; i < a.size(); ++i) {
		ans += test(a[i]);
		if (i + 1 < a.size() && a[i] + 1 < a[i + 1]) ans += test(a[i] + 1) * (a[i + 1] - (a[i] + 1));
	}

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
