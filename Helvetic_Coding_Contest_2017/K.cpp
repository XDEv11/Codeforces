//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <set>
#include <algorithm>

using namespace std;

namespace K {
	int n, k;
	vector<vector<pair<int, int>>> adj{};
	pair<int, int> dfs(int u, int w = -1) {
		vector<pair<int, int>> a{};
		for (auto& [v, c] : adj[u]) {
			if (v == w) continue;
			auto [x, y]{dfs(v, u)};
			a.emplace_back(c + x, c + y);
		}
		multiset<int> ms{};
		for (auto& [x, y] : a) {
			ms.insert(x);
			if (ms.size() > k) ms.erase(ms.begin());
		}
		int s1{}, s2{};
		for (auto& x : ms) s1 += x;
		if (ms.size() == k) {
			for (auto& [x, y] : a) s2 = max(s2, y + s1 - (ms.count(x) ? x : *ms.begin()));
			s1 -= *ms.begin();
		} else {
			for (auto& [x, y] : a) s2 = max(s2, y + s1 - x);
		}
		return {s1, s2};
	}
	bool solve() {
		if (!(cin >> n >> k)) return false;
		adj.assign(n, {});
		for (int _{0}; _ < n - 1; ++_) {
			int u, v, c;
			cin >> u >> v >> c;
			adj[u].emplace_back(v, c);
			adj[v].emplace_back(u, c);
		}

		int ans{dfs(0).se};

		return cout << ans << '\n', true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (K::solve()) ;
}
